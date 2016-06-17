#pragma once

enum Bit{ Zero, One };

template<int T>
class gray_code
{
public:
	gray_code(const std::bitset<T>& gray);
	static gray_code from_binary(const std::bitset<T>& binary);
	static gray_code from_gray(const std::bitset<T>& gray);
	static gray_code from_integer(unsigned int a);
	static gray_code from_string(const std::string& s);
	~gray_code(){};
	void print_gray() const;
	void print_binary() const;
	gray_code increment() const;
private:
	std::bitset<T> gray_;
	std::bitset<T> binary_;
};



template<int T>
gray_code<T>::gray_code(const std::bitset<T>& gray) : gray_(gray), binary_()
{
	for (int i = gray_.size() - 1; i >= 0; i--){
		if (i == gray_.size() - 1){
			binary_[gray_.size() - 1] = gray_[gray_.size() - 1];
		}
		else {
			if (gray_[i] == 0){
				binary_[i] = binary_[i + 1];
			}
			else {
				binary_[i] = !binary_[i + 1];
			}
		}
	}
}

template<int T>
gray_code<T> gray_code<T>::from_binary(const std::bitset<T>& binary)
{
	std::bitset<T> gray;
	for (int i = binary.size() - 1; i >= 0; i--){
		if (i == binary.size() - 1){
			gray[binary.size() - 1] = binary[binary.size() - 1];
		}
		else {
			gray[i] = (binary[i] ^ binary[i + 1]);
		}
	}
	return gray_code(gray);
}


template<int T>
gray_code<T> gray_code<T>::from_gray(const std::bitset<T>& gray)
{
	return gray_code(gray);
}

template<int T>
gray_code<T> gray_code<T>::from_integer(unsigned int a)
{
	return gray_code::from_binary(std::bitset<T>(a));
}

template<int T>
gray_code<T> gray_code<T>::from_string(const std::string& s)
{
	return gray_code::from_binary(std::bitset<T>(s));
}

template<int T>
gray_code<T> gray_code<T>::increment() const {
	return gray_code::from_integer(int(binary_.to_ulong()) + 1);
}


template<int T>
void gray_code<T>::print_gray() const
{
	std::cout << "gray" << std::endl;
	std::cout << gray_;
	std::cout << std::endl;
}


template<int T>
void gray_code<T>::print_binary() const
{
	std::cout << "binary" << std::endl;
	std::cout << binary_;
	std::cout << std::endl;
}
