#ifndef STC_H
#define STC_H

#include <exception>
#include <memory>

namespace _Xception
{
	template<class _AnyClass> class STC	: private std::auto_ptr<_AnyClass>	//Store and Reset class
	{
		std::unexpected_handler old_u;										//by default unexpected calls terminate() which calls abort(), both can be modified here
		std::terminate_handler old_t;
	public:
		STC(_AnyClass *_C, std::unexpected_handler u =0, std::terminate_handler t =0)
			try
			:	std::auto_ptr<_AnyClass>(_C),
				old_u(0),
				old_t(0)
		{
			if(u==0) return;
			else if(t==0)
			{
				old_u = set_unexpected(u);
				return;
			}
			else
			{
				old_t = set_terminate(t);
				old_u = set_unexpected(u);
			}
		}
		catch(...)
		{
			cout<<"\nCaught an Exception while Constructing STC:\n";
			throw;
		}

		virtual const STC* new_STC()	const	{return new const STC(this->get(), old_u, old_t);}
		virtual const STC* clone()				{return new const STC(*this);}

		
		using std::auto_ptr<_AnyClass>::get;							//automatically throw() as _THROW0(), _noexcept, _NoThrow
		using std::auto_ptr<_AnyClass>::operator->;						//_THROW0 ...#define _THROW0() throw()
		using std::auto_ptr<_AnyClass>::operator*;
		using std::auto_ptr<_AnyClass>::reset;
		using std::auto_ptr<_AnyClass>::release;

		/*_AnyClass *const get() const throw()
		{
			return std::auto_ptr<_AnyClass>::get();
		}*/
		
		/*_AnyClass *const operator->() const throw()
		{
			return get();
		}*/

		/*const _AnyClass& operator*() const throw()
		{
			return (*get());
		}*/

		virtual ~STC()
		try
		{
			if(old_u==0) return;
			else if(old_t==0)
			{
				set_unexpected(old_u);
				return;
			}
			else
			{
				set_terminate(old_t);
				set_unexpected(old_u);
			}
		}
		catch(...)
		{
			cout<<"\nCaught an exception while Destructing STC:\n";
			throw;
		}
	};
}

#endif