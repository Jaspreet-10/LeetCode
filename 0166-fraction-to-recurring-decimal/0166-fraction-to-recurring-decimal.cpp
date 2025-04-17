class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
    
    string answer = "";

    // Add the negative sign if needed
    if ((numerator < 0) ^ (denominator < 0)) answer += "-";

    // Convert to long to handle overflow
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);

    // Append the integer part
    long long integerPart = num / den;
    answer += to_string(integerPart);

    long long remainder = num % den;
    if (remainder == 0) return answer;

    // Decimal part begins
    answer += ".";
    unordered_map<long long, int> seen;  // maps remainder to position in answer

    while (remainder != 0) {
        if (seen.count(remainder)) {
            // Repeating part detected
            answer.insert(seen[remainder], "(");
            answer += ")";
            break;
        }

        seen[remainder] = answer.size();

        remainder *= 10;
        answer += to_string(remainder / den);
        remainder = remainder % den;
    }

    return answer;
    }
};