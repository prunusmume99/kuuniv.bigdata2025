#include "data_process.hpp"
#include <algorithm>

// 생성자
DataProcessor::DataProcessor(std::vector<std::string> data) : data_(data) {}

// 문자열 길이 기준 정렬
auto DataProcessor::sort_by_length() -> std::vector<std::string>
{
    auto result = data_;
    std::sort(result.begin(), 
              result.end(),
              [](const std::string &a, const std::string &b) 
              {
                  return a.length() < b.length();
              });
    return result;
}

// 접두사 기준 필터링
auto DataProcessor::filter_by_prefix(const std::string &prefix) -> std::vector<std::string>
{
    std::vector<std::string> result;
    std::copy_if(data_.begin(), 
                 data_.end(), 
                 std::back_inserter(result), 
                 [&prefix](const std::string &s) 
                 {
                     return s.find(prefix) == 0;
                 });

    return result;
}
