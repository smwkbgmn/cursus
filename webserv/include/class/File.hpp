#ifndef FILE_HPP
# define FILE_HPP

# include <fstream>

# include <string>
# include <exception>

/*
	app		(append) Set the stream's position indicator to the end of the stream before each output operation.
	ate		(at end) Set the stream's position indicator to the end of the stream on opening.
	binary	(binary) Consider stream as binary rather than text.
	in		(input) Allow input operations on the stream.
	out		(output) Allow output operations on the stream.
	trunc	(truncate) Any current content is discarded, assuming a length of zero on opening.
*/

enum Mode { R, R_BINARY, W };

class File {
	public:
		std::fstream	fs;

		File( const std::string&, int );
		~File( void );
	
	private:
		File( void );
		File( const File& );
		File&	operator=( const File& );

};

#endif