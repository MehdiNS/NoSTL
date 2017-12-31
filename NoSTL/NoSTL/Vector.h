#pragma once
#include "Algorithm.h"

namespace nostd
{
	template<class T>
	class vector
	{
	public:
		using value_type = T;
		using size_type = int;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = value_type*;
		using const_iterator = const value_type*;

	private:
		value_type *_data;
		size_type _size;
		size_type _capacity;

	public:
		size_type size() const noexcept { return _size; }
		size_type capacity() const noexcept { return _capacity; }
		bool empty() const noexcept { return !size(); }

	private:
		bool full() const noexcept { return size() == capacity(); }

	public:
		~vector() noexcept { delete[] _data; }
		vector() noexcept : _data{}, _size{}, _capacity{} {}
		
		vector(const vector& v) noexcept :
			_data{ new value_type[v.size()] },
			_size{ v.size() },
			_capacity{ v.size() }
		{
			nostd::copy(v.begin(), v.end(), begin());
		}

		vector(size_type n, const value_type& init) noexcept :
		_data{ new value_type[n] },
			_size{ n },
			_capacity{ n }
		{
			nostd::fill(begin(), end(), init);
		}

		iterator begin() noexcept { return _data; }
		const_iterator begin() const noexcept { return _data; }
		const_iterator cbegin() const noexcept { return begin(); }
		iterator end() noexcept { return begin() + size(); }
		const_iterator end() const noexcept { return begin() + size(); }
		const_iterator cend() const noexcept { return end(); }

		void grow() {
			// We grow the vector to the next power of two
			// TODO : make this generic to try other strategies
			size_type newCapacity = size() ? size() << 1 : 1;
			value_type* p = new value_type[newCapacity];
			try {
				nostd::copy(begin(), end(), p);
				delete[] _data;
				_data = p;
				_capacity = newCapacity;
			}
			catch (...) {
				delete[] p;
				throw;
			}
		}

		void push_back(const_reference val) {
			if (full())
				grow();
			_data[size()] = val;
			++_size;
		}

		reference operator[](size_type n) noexcept { return _data[n]; }
		const_reference operator[](size_type n) const noexcept { return _data[n]; }

		bool operator==(const vector &other) const
		{
			return size() == other.size() && nostd::equal(begin(), end(), other.begin());
		}

		bool operator!=(const vector &other) const
		{
			return !(*this == other);
		}

		void swap(vector& v) noexcept
		{
			using nostd::swap;
			swap(_data, v._data);
			swap(_size, v._size);
			swap(_capacity, v._capacity);
		}

		vector& operator=(const vector& v)
		{
			vector{ v }.swap(*this);
			return *this;
		}
	};


}