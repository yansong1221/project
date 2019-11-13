#ifndef __SPIN_LOCK_h__
#define __SPIN_LOCK_h__
#include <atomic>

class SpinLock
{
	std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	SpinLock() = default;
	SpinLock(const SpinLock&) = delete;
	SpinLock& operator= (const SpinLock&) = delete;

	void lock()
	{
		while (flag.test_and_set(std::memory_order_acquire))
			;
	}
	void unlock()
	{
		flag.clear(std::memory_order_release);
	}

};

#endif /* __SPIN_LOCK_h__ */

