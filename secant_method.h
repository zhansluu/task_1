#ifndef SECANT_METHOD_H_INCLUDED
#define SECANT_METHOD_H_INCLUDED
#include "functions.h"
#include <iomanip>

/*�������� ������� ���������� ������ �������
    1)f(a)*f(b) < 0 - ����������� ����������, ��� ��� ������� �� �������� �����
    2)f'(x),f''(x) - ��������� ����� �� [a,b]
    3)f(x_0)f''(x_0) > 0 , x_0 \in [a,b]
    */

/*����� �������
������� �� ������ ������� � ���, ��� �� �������� �����������
��� �������� ����� �� ������������ ��������� �� �������� ���������� �����������������.*/
    void secant_method (double a, double b, double epsilon)
    {
        std::cout << "����� �������" << std::endl;
        if (getDerivativeValue(a)*getDerivativeValue(b)<0 ||
            getSecondDerivativeValue(a)*getSecondDerivativeValue(b)<0)
                std::cout << "������� � ���������� �� ���������, ��� ��� ����������� ������ ���� �� ������ �������" << std::endl << std::endl;
        else
        {
            int random = rand()*(b-a)/32767;
            double previous_solut = a + random*(b-a);

            while(getSecondDerivativeValue(previous_solut) * func(previous_solut) <= 0)
                previous_solut = a + rand()*(b - a)/32767;

            double current_solut = a + random*(b - a);
            double next_solut = current_solut -
                (func(current_solut) / (func(current_solut) - func(previous_solut)) *
                        (current_solut - previous_solut));
            size_t counter = 0;
            while(fabs(current_solut - previous_solut) >= epsilon) {
                previous_solut = current_solut;
                current_solut = next_solut;
                next_solut = current_solut -
                        (func(current_solut) / (func(current_solut) - func(previous_solut)) *
                                (current_solut - previous_solut));
                ++counter;
            }

            std::cout << "x = " << std::setprecision(15) << current_solut << std::endl;
            std::cout << "|x_m -  x_{m-1}| = " << fabs(current_solut - previous_solut) << std::endl;
            std::cout << "���������� ������ ������� ��� ������������� �������: " << fabs(func(current_solut) - 0) << std::endl;
            std::cout << "���������� ����� ��� ���������� �������� �������: " << counter << std::endl << std::endl;
        }
    }


#endif // SECANT_METHOD_H_INCLUDED
