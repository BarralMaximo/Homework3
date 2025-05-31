#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

template<typename T>
class DataProcessor {
private:
    std::vector<T> vec_data; // Para doubles y strings
    std::vector<std::vector<int>> matrix_data; // Para matrices de enteros

public:
    // Agregar un valor individual (para doubles y strings)
    void addValue(const T& value) {
        if constexpr (std::is_same_v<T, double> || std::is_same_v<T, std::string>) {
            vec_data.push_back(value);
        } else {
            static_assert(std::is_same_v<T, int>, "Solo se soportan doubles, strings o matrices de enteros");
        }
    }

    // Agregar una fila de matriz (para enteros)
    void addMatrixRow(const std::vector<int>& row) {
        if constexpr (std::is_same_v<T, int>) {
            matrix_data.push_back(row);
        } else {
            static_assert(std::is_same_v<T, int>, "La entrada de matriz solo se soporta para tipo int");
        }
    }

    // Convertir datos a formato JSON
    std::string toJsonString() const {
        std::string result;

        if constexpr (std::is_same_v<T, double>) {
            result = "[";
            for (size_t i = 0; i < vec_data.size(); ++i) {
                // Evitar ceros finales innecesarios en doubles
                std::string num = std::to_string(vec_data[i]);
                num.erase(num.find_last_not_of('0') + 1, std::string::npos);
                num.erase(num.find_last_not_of('.') + 1, std::string::npos);
                result += num;
                if (i < vec_data.size() - 1) result += ", ";
            }
            result += "]";
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            result = "[";
            for (size_t i = 0; i < vec_data.size(); ++i) {
                result += "\"" + vec_data[i] + "\"";
                if (i < vec_data.size() - 1) result += ", ";
            }
            result += "]";
        }
        else if constexpr (std::is_same_v<T, int>) {
            result = "[\n        ";
            for (size_t i = 0; i < matrix_data.size(); ++i) {
                result += "[";
                for (size_t j = 0; j < matrix_data[i].size(); ++j) {
                    result += std::to_string(matrix_data[i][j]);
                    if (j < matrix_data[i].size() - 1) result += ",";
                }
                result += "]";
                if (i < matrix_data.size() - 1) result += ",\n        ";
            }
            result += "\n    ]";
        }

        return result;
    }
};

class JsonBuilder {
private:
    std::vector<std::pair<std::string, std::string>> labeled_data;

public:
    void addLabeledData(const std::string& label, const std::string& data) {labeled_data.emplace_back(label, data);}

    // Construir y devolver el JSON completo
    std::string buildJson() const {
        std::string result = "{";
        for (size_t i = 0; i < labeled_data.size(); ++i) {
            result += "    \"" + labeled_data[i].first + "\": " + labeled_data[i].second;
            if (i < labeled_data.size() - 1) result += ",";
            result += "\n";
        }
        result += "}";
        return result;
    }

    void printJson() const {std::cout << buildJson() << std::endl;}
};