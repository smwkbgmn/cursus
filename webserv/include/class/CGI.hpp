#ifndef CGI_HPP
# define CGI_HPP

# include <unistd.h>
# include <sys/wait.h>
# include <new>

# include "HTTP.hpp"

typedef struct {
	pid_t	pid;
	pipe_t	fd[2];
	stat_t	stat;
}	process_t;

class CGI {
	public:
		typedef stat_t	( *fn_t )( const process_t&, char** );

		static void		init( const name_t& );

		static void		GET( const Request&, char**, size_t& );
		static void		POST( const Request&, char**, size_t& );

	private:
		static void		_argvBuild( vec_cstr_t&, const str_t&, const str_t& );

		static void		_detach( process_t&, fn_t, vec_cstr_t& );
		static void		_redirect( const process_t& );
		static stat_t	_execute( const process_t&, char** );

		static void		_wait( process_t& );
		static void		_read( process_t&, char**, size_t& );
};


#endif