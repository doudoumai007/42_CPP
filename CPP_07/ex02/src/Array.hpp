#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;
	
	public:
		Array(): _data(NULL), _size(0) {}
		Array(unsigned int n): _size(n)
		{
			_data = new T[n]();
		}
		Array(const Array& other): _size(other._size)
		{
			if (_size == 0)
				_data = NULL;
			else
			{
				_data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				T* new_data = NULL;
				if (other._size > 0)
				{
					new_data = new T[other._size];
					for (unsigned int i = 0; i < other._size; ++i)
						new_data[i] = other._data[i];
				}
				delete[](_data);
				_data = new_data;
				_size = other._size;
			}
			return (*this);
		}
		~Array() {}

		//Overload subscript operator: []
		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw (std::out_of_range("Index out of range"));
			return (_data[i]);
		}
		//Size
		unsigned int size() const
		{
			return (_size);
		}

};


#endif