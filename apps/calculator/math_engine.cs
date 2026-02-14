/* ************************************************************
 * ARkalpyOS - Floating Point Math Engine
 * Language: C#
 * ************************************************************
 */

using System;

public class CalculatorEngine {
    public static double Solve(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
                if (b == 0) return 0; // Proteção contra divisão por zero
                return a / b;
            default: return 0;
        }
    }

    public static string FormatResult(double res) {
        return res.ToString("N2"); // Formata com 2 casas decimais
    }
}
