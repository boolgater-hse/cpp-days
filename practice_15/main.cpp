#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Shape.hpp"

template <typename T>
T& checkInput(T& value)
{
    while (true)
    {
        if (std::cin >> value)
        {
            break;
        }
        else
        {
            std::cout << "Bad input! Try again." << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        }
    }

    return value;
}

int main()
{
    std::vector <Shape*> shapes;

    while (true)
    {
        system("cls");
        std::cout << "Menu:\n" << std::endl;

        std::cout << "1 - Create shape" << std::endl;
        std::cout << "2 - Print my shapes" << std::endl;
        std::cout << "3 - Exit" << std::endl;

        unsigned char command = getch();

        switch (command)
        {
            case '1':
                system("cls");

                while (true)
                {
                    std::cout << "1 - Rectangle" << std::endl;
                    std::cout << "2 - Triangle" << std::endl;
                    std::cout << "3 - Circle" << std::endl;
                    std::cout << "4 - Back" << std::endl;

                    command = getch();

                    if (command == '1')
                    {
                        std::cout << "\nEnter width and height:" << std::endl;
                        double width = checkInput(width);
                        double height = checkInput(height);
                        auto temp = new Rectangle(width, height);
                        if (temp->isValid())
                        {
                            shapes.push_back(temp);
                            std::cout << "Shape successfully created" << std::endl << std::endl;
                        }
                        else
                        {
                            std::cout << "Wrong input data! Shape didn't created" << std::endl << std::endl;
                        }
                    }
                    else if (command == '2')
                    {
                        std::cout << std::endl;
                        std::cout << "Enter three coords of points:" << std::endl;
                        std::vector <Point2D> coords;
                        for (int i = 0; i < 3; ++i)
                        {
                            std::cout << "Enter " << i + 1 << " pair of coords" << std::endl;
                            double one = checkInput(one);
                            double two = checkInput(two);
                            coords.push_back(Point2D(one, two));
                        }
                        auto temp = new Triangle(coords[0], coords[1], coords[2]);
                        if (temp->isValid())
                        {
                            shapes.push_back(temp);
                            std::cout << "Shape successfully created" << std::endl << std::endl;
                        }
                        else
                        {
                            std::cout << "Wrong input data! Shape didn't created" << std::endl << std::endl;
                        }
                    }
                    else if (command == '3')
                    {
                        std::cout << "\nEnter radius:" << std::endl;
                        double radius = checkInput(radius);
                        auto temp = new Circle(radius);
                        if (temp->isValid())
                        {
                            shapes.push_back(temp);
                            std::cout << "Shape successfully created" << std::endl << std::endl;
                        }
                        else
                        {
                            std::cout << "Wrong input data! Shape didn't created" << std::endl << std::endl;
                        }
                    }
                    else if (command == '4')
                    {
                        break;
                    }
                    else
                    {
                        std::cout << std::endl;
                    }
                }

                break;
            case '2':
                system("cls");

                if (shapes.empty())
                {
                    std::cout << "You have no shapes yet" << std::endl << std::endl;
                    std::cout << "Press any key to go back" << std::endl;
                    getch();

                    break;
                }

                std::sort(shapes.begin(), shapes.end(), [](Shape* one, Shape* two)
                {
                    return one->getPerimeter() > two->getPerimeter();
                });

                for (size_t i = 0; i < shapes.size(); ++i)
                {
                    std::cout << "ID: " << shapes[i]->getId() << " " << "Perimeter: " << shapes[i]->getPerimeter()
                              << std::endl;
                }

                std::cout << std::endl;
                std::cout << "Press any key to go back" << std::endl;
                getch();

                break;
            case '3':
                for (auto i: shapes)
                {
                    delete i;
                }

                return 0;
            default:
                break;
        }
    }
}
