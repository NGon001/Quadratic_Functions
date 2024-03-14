//QuadraticEqtion  x=-(b+-sqr(b^2-4ac))/2a  / ax^2+bx+c=0 - general / a(x-h)^2+k - vertex form / y=a(x-r1)(x-r2) - factored form

#include <string>
#include <iostream>
#include <string>
#include <cstdlib>

class QuadraticFunction
{
public:
    float a, b, c;
    std::string equation;
    int x_intersept_count;
    float Discriminant;
    float x1,x2;
    void EnterEquation()
    {
        std::cout << "Enter the quadratic equation in general form (ax^2 + bx + c): ";
        std::getline(std::cin, equation);
    }
    // Function to determine coefficients a, b, and c
    void DetermineABC()
    {
        // Find the positions of 'x^2', 'x', and '+' or '-' for coefficient extraction
        size_t pos_x2 = equation.find("x^2");
        size_t pos_x = equation.find("x", pos_x2 + 1);
        size_t pos_separator_c = equation.find_last_of("+-");

        // Extract coefficient 'a' substring
        std::string a_str;
        if (pos_x2 != std::string::npos) {
            a_str = equation.substr(0, pos_x2);
        }
        else {
            a_str = "1"; // If 'x^2' is missing, 'a' is 1
        }
        float sign_a = determineCoefficientSign(a_str, ' ');
        a = atof(a_str.c_str()) * sign_a;

        // Extract coefficient 'b' substring
        std::string b_str;
        if (pos_x != std::string::npos) {
            if (pos_x2 != std::string::npos) {
                b_str = equation.substr(pos_x2 + 3, pos_x - (pos_x2 + 3));
            }
            else {
                b_str = equation.substr(pos_x2 + 1, pos_x - (pos_x2 + 1));
            }
        }
        else {
            // If 'x' is missing, 'b' is 0
            b_str = "0";
        }
        float sign_b = determineCoefficientSign(b_str, equation[pos_x - 1]);
        b = atof(b_str.c_str()) * sign_b;

        // Extract coefficient 'c' substring
        std::string c_str;
        if (pos_separator_c != std::string::npos) {
            c_str = equation.substr(pos_separator_c);
        }
        else {
            // If '+' or '-' is missing, 'c' is 0
            c_str = "0";
        }
        float sign_c = determineCoefficientSign(c_str, equation[pos_separator_c - 1]);
        c = atof(c_str.c_str()) * sign_c;
    }
    void Descriminant()
    {
        Discriminant = (b *b) - 4 * (a * c);
    }
    // Function to determine number of x-intersepts
    int X_InterseptsCount()
    {
        x_intersept_count = (Discriminant > 0) ? 2 : (Discriminant < 0) ? 0 : 1;
        return x_intersept_count;
    }  
    void Roots()
    {
        x1 = rounding((-(b)+sqrt(Discriminant)) / (2 * a));
        x2 = rounding((-(b)-sqrt(Discriminant)) / (2 * a));
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << std::endl;
        return;
    }
    float xAxis()
    {
        return round((x1 + x2) / 2);
    }
    void Vertex()
    {
       float x_vertex = xAxis();
       float y_vertex = a * x_vertex * x_vertex + b * x_vertex + c;
       std::cout << "x_vertex = " << x_vertex << ", y_vertex = " << y_vertex << std::endl;
       return;
    }
    void Start()
    {
        EnterEquation();
        DetermineABC();
        Descriminant();
        X_InterseptsCount();      
    }

private:
    float determineCoefficientSign(const std::string& term_str, char prev_sign) {
        if (term_str.empty()) {
            return 1.0f;
        }
        else {
            char sign = term_str[0];
            return (prev_sign == '-') ? -1.0f : 1.0f;
        }
    }
    float rounding(float number)
    {
        double rounded_number = std::ceil(number * 100) / 100;

        std::cout << "Original number: " << number << std::endl;
        std::cout << "Rounded number: " << rounded_number << std::endl;
        return rounded_number;
    }
};