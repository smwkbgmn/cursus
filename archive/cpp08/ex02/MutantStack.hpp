#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename MutantStack<T>::stack								stack;

		/* stack::container_type = deque
		unless declare stack through std::stack<T, Container> */
		typedef typename stack::container_type::iterator					iterator;
		typedef typename stack::container_type::reverse_iterator			reverse_iterator;
		typedef typename stack::container_type::const_iterator				const_iterator;
		typedef typename stack::container_type::const_reverse_iterator		const_reverse_iterator;

	public:
		MutantStack( void ): stack() {}
		MutantStack( const MutantStack& target ): stack(target) {}
		~MutantStack( void ) {}

	public:
		iterator				begin( void ) { return stack::c.begin(); }
		iterator				end( void ) { return stack::c.end(); }
		reverse_iterator		rbegin( void ) { return stack::c.rbegin(); }
		reverse_iterator		rend( void ) { return stack::c.rend(); }
		const_iterator			cbegin( void ) { return stack::c.cbegin(); }
		const_iterator			cend( void ) { return stack::c.cend(); }
		const_reverse_iterator	crbegin( void ) { return stack::c.crbegin(); }
		const_reverse_iterator	crend( void ) { return stack::c.crend(); }

	public:
		MutantStack&			operator=( const MutantStack& target ) {
			if (this != target)
				stack::operator=(target);
			return *this;
		}
};

#endif