#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, typename Compare>
std::vector<std::size_t> sort_permutation(
    const std::vector<T>& vec,
    Compare& compare)
{
    std::vector<std::size_t> p(vec.size());
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),
        [&](std::size_t i, std::size_t j){ return compare(vec[i], vec[j]); });
    return p;
}

template <typename T>
std::vector<T> apply_permutation(
    const std::vector<T>& vec,
    const std::vector<std::size_t>& p)
{
    std::vector<T> sorted_vec(vec.size());
    std::transform(p.begin(), p.end(), sorted_vec.begin(),
        [&](std::size_t i){ return vec[i]; });
    return sorted_vec;
}

template <typename T>
void apply_permutation_in_place(
    std::vector<T>& vec,
    const std::vector<std::size_t>& p)
{
    std::vector<bool> done(vec.size());
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        if (done[i])
        {
            continue;
        }
        done[i] = true;
        std::size_t prev_j = i;
        std::size_t j = p[i];
        while (i != j)
        {
            std::swap(vec[prev_j], vec[j]);
            done[j] = true;
            prev_j = j;
            j = p[j];
        }
    }
}

int main()
{
    vector<string> vectorA;
    vector<int> vectorB;

    vectorA.push_back(1);
    vectorA.push_back(3);
    vectorA.push_back(2);
    vectorB.push_back(string("Bla"));
    vectorB.push_back(string("de"));
    vectorB.push_back(string("cdd"));


    auto p = sort_permutation(vectorA,
        [](T const& a, T const& b){a<b });

    vectorA = apply_permutation(vectorA, p);
    vectorB = apply_permutation(vectorB, p);
}
