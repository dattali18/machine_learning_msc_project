#include <iostream>

int predict(double cp, double ca, double thal, double exang,
            double oldpeak, double trestbps, double chol,
            double age, double slope, double thalach) {
    if (cp <= 0.50) {
        if (ca <= 0.50) {
            if (thal <= 2.50) {
                if (exang <= 0.50) {
                    // truncated branch of depth 4
                    return -1;
                } else { // exang > 0.50
                    // truncated branch of depth 4
                    return -1;
                }
            } else { // thal > 2.50
                if (oldpeak <= 0.65) {
                    // truncated branch of depth 3
                    return -1;
                } else { // oldpeak > 0.65
                    return 0;
                }
            }
        } else { // ca > 0.50
            if (trestbps <= 109.00) {
                if (chol <= 233.50) {
                    return 1;
                } else { // chol > 233.50
                    return 0;
                }
            } else { // trestbps > 109.00
                if (age <= 63.50) {
                    return 0;
                } else { // age > 63.50
                    // truncated branch of depth 3
                    return -1;
                }
            }
        }
    } else { // cp > 0.50
        if (thal <= 2.50) {
            if (oldpeak <= 2.10) {
                if (age <= 55.50) {
                    // truncated branch of depth 5
                    return -1;
                } else { // age > 55.50
                    // truncated branch of depth 6
                    return -1;
                }
            } else { // oldpeak > 2.10
                if (slope <= 0.50) {
                    return 1;
                } else { // slope > 0.50
                    // truncated branch of depth 2
                    return -1;
                }
            }
        } else { // thal > 2.50
            if (thalach <= 132.50) {
                return 0;
            } else { // thalach > 132.50
                if (oldpeak <= 1.95) {
                    // truncated branch of depth 6
                    return -1;
                } else { // oldpeak > 1.95
                    // truncated branch of depth 2
                    return -1;
                }
            }
        }
    }
}
