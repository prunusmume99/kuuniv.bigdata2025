#pragma once
#include <string>
#include <vector>

class DataProcessor
{
public:
    DataProcessor(std::vector<std::string> data);
    auto sort_by_length() -> std::vector<std::string>;
    auto filter_by_prefix(const std::string &prefix) -> std::vector<std::string>;
    std::vector<std::string> data_;
};