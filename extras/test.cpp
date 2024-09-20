/*******************************************************************************

    C++ source code to support stdcpp unittests

    In order to ensure compatibility with C++, we instantiate those
    C++ templates (with gcc, clang, or cl) and use them from the D code.

*******************************************************************************/

// #include <list>
// #include <string>
#include <vector>
// #include <set>

namespace stdcpp {
    namespace test {
        template<typename T>
        std::size_t cppSizeOf() {
            return sizeof(T);
        }

        /// Returns the result of `std::string` capacity with the provided string
        std::size_t stringCapacity (char const* str) {
            std::string s(str);
            return s.capacity();
        }
    };
};

// template std::size_t stdcpp::test::cppSizeOf<std::string>();

// template class std::list<int>;
// template std::size_t stdcpp::test::cppSizeOf<std::list<int> >();

// template class std::vector<int>;
// template std::size_t stdcpp::test::cppSizeOf<std::vector<int> >();

// template class std::set<int>;
// template std::size_t stdcpp::test::cppSizeOf<std::set<int> >();

#define VECTOR_INSTANTIATION(TYPE)                                  \
template std::size_t stdcpp::test::cppSizeOf<std::vector<TYPE> >(); \
template class std::vector<TYPE>;                                   \
__attribute__((__visibility__("hidden")))                           \
void vec_instantiation_helper_##TYPE() {                            \
    std::vector<TYPE> v(1);                                         \
    v.push_back(TYPE());                                            \
    std::vector<TYPE> w(1, TYPE());                                 \
    std::vector<TYPE> y(w);                                         \
    w = v;                                                          \
    w.assign(1, TYPE());                                            \
    w.reserve(1);                                                   \
    w.resize(1);                                                    \
    w.swap(v);                                                      \
}

// Use the macro for int and any other types
VECTOR_INSTANTIATION(int)
VECTOR_INSTANTIATION(float) // Example for float
VECTOR_INSTANTIATION(double) // Example for double
VECTOR_INSTANTIATION(char)
