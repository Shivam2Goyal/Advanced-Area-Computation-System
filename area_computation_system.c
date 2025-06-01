#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

float area; // Global area variable

// Function to calculate area under exponential curve
float Exponential_Curve() {
    float a, b;
    printf("Enter the parameters (a, b) of the exponential curve of form a^(bx): ");
    scanf("%f %f", &a, &b);

    float x1, x2;
    printf("Enter the lower value of x (x1): ");
    scanf("%f", &x1);
    printf("Enter the higher value of x (x2): ");
    scanf("%f", &x2);

    int n;
    printf("Enter the number of segments to divide the interval: ");
    scanf("%d", &n);

    float h = (x2 - x1) / n;
    float a1 = 0;

    for (int i = 0; i < n; i++) {
        a1 += pow(a, b * (x1 + h * i)) * h;
    }

    area = a1;
    printf("Area = %s%.2f%s", BOLD, area, RESET);
    return area;
}

// Function to calculate area under a linear curve
float Linear_Curve() {
    printf("The linear function is of the form: y = mx + c\n");
    float m, c, x1, x2;
    printf("Enter the slope (m): ");
    scanf("%f", &m);
    printf("Enter the y-intercept (c): ");
    scanf("%f", &c);
    printf("Enter the lower value of x (x1): ");
    scanf("%f", &x1);
    printf("Enter the higher value of x (x2): ");
    scanf("%f", &x2);

    if (x1 > x2) {
        printf("Invalid range: x1 should be less than x2.\n");
        return 0;
    }

    float root = -c / m;
    if (x1 < root && x2 > root) {
        float a1 = fabs((root - x1) * ((m * x1) + c) / 2);
        float a2 = fabs((x2 - root) * ((m * x2) + c) / 2);
        area = a1 + a2;
    } else {
        area = fabs(((m * x1 + c) + (m * x2 + c)) / 2) * (x2 - x1);
    }

    printf("Area = %s%.2f%s", BOLD, area, RESET);
    return area;
}

// Function to calculate area under a quadratic curve
float Quadratic_Curve() {
    printf("Quadratic function form: ax^2 + bx + c\n");
    float a, b, c, p, q;
    printf("Enter values a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Enter interval [p, q]: ");
    scanf("%f %f", &p, &q);

    int n;
    printf("Enter number of segments: ");
    scanf("%d", &n);

    float h = (q - p) / n;
    float a1 = 0;

    for (int i = 0; i < n; i++) {
        float x = p + h * i;
        a1 += fabs((a * x * x + b * x + c) * h);
    }

    area = a1;
    printf("Area = %s%.2f%s", BOLD, area, RESET);
    return area;
}

// Rectangle area
float Rectangle() {
    float b, l;
    printf("Enter Breadth: ");
    scanf("%f", &b);
    printf("Enter Length: ");
    scanf("%f", &l);
    area = fabs(b) * fabs(l);
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Triangle area using two sides and angle between them
float Triangle() {
    float theta, s1, s2;
    printf("Enter angle (in degrees) between two sides: ");
    scanf("%f", &theta);
    theta = 3.1416 / 180 * theta;

    printf("Enter length of side 1: ");
    scanf("%f", &s1);
    printf("Enter length of side 2: ");
    scanf("%f", &s2);

    area = 0.5 * fabs(s1) * fabs(s2) * fabs(sin(theta));
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Ellipse area
float Ellipse() {
    float a, b;
    printf("Enter major axis length: ");
    scanf("%f", &a);
    printf("Enter minor axis length: ");
    scanf("%f", &b);
    area = 3.1416 * fabs(a / 2) * fabs(b / 2);
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Trapezium area
float Trapezium() {
    float a, b, h;
    printf("Enter first parallel side: ");
    scanf("%f", &a);
    printf("Enter second parallel side: ");
    scanf("%f", &b);
    printf("Enter height: ");
    scanf("%f", &h);
    area = ((fabs(a) + fabs(b)) / 2) * fabs(h);
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Circle area
float Circle() {
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    area = 3.1416 * fabs(r) * fabs(r);
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Regular Hexagon area
float Regular_Hexagon() {
    float a;
    printf("Enter side length: ");
    scanf("%f", &a);
    area = 1.5 * 1.732 * fabs(a) * fabs(a);  // Using approx. √3 = 1.732
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Rectangular arena (rectangle with semicircles at ends)
float Rectangular_Arena() {
    float l, b;
    printf("Enter length: ");
    scanf("%f", &l);
    printf("Enter breadth: ");
    scanf("%f", &b);

    float r = b / 2;
    area = (3.1416 * fabs(r) * fabs(r)) + (fabs(l) * fabs(b));
    printf("Area = %s%.2f%s m²", BOLD, area, RESET);
    return area;
}

// Area conversion
void Convert_Units() {
    int opt;
    printf("\nConvert area to other units?\nEnter 1 for Yes or 0 for No: ");
    scanf("%d", &opt);

    if (opt == 1) {
        int unit;
        printf("Choose unit:\n1. cm²\n2. in²\n");
        scanf("%d", &unit);

        if (unit == 1) {
            area *= 10000; // m² to cm²
        } else if (unit == 2) {
            area *= 1550; // m² to in²
        } else {
            printf("Invalid unit selected.\n");
            return;
        }

        printf("Converted Area = %s%.2f%s", BOLD, area, RESET);
    } else if (opt != 0) {
        printf("Invalid choice for unit conversion.\n");
    }
}

// Main function with menu
int main() {
    int choice;

    do {
        printf("\n%sArea Calculator - Choose a Shape or Curve:%s\n", BOLD, RESET);
        printf("1. Rectangle\n2. Triangle\n3. Ellipse\n4. Trapezium\n5. Circle\n6. Regular Hexagon\n");
        printf("7. Rectangular Arena\n8. Linear Curve\n9. Quadratic Curve\n10. Exponential Curve\n");
        printf("Enter your choice (1-10): ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: Rectangle(); break;
            case 2: Triangle(); break;
            case 3: Ellipse(); break;
            case 4: Trapezium(); break;
            case 5: Circle(); break;
            case 6: Regular_Hexagon(); break;
            case 7: Rectangular_Arena(); break;
            case 8: Linear_Curve(); break;
            case 9: Quadratic_Curve(); break;
            case 10: Exponential_Curve(); break;
            default: printf("Invalid choice.\n"); continue;
        }

        Convert_Units();

        printf("\nDo you want to calculate another area? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\n%sThank you! HAPPY CODING!%s\n", BOLD, RESET);
    return 0;
}
