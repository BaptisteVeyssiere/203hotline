//
// calc.cpp for Project-Master in /home/veyssi_b/rendu/tek2/Math/203hotline
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Mar 13 16:24:31 2017 Baptiste Veyssiere
// Last update Thu Mar 23 14:20:45 2017 Baptiste Veyssiere
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <sys/time.h>

int	proba(double n, double k)
{
  long double	Cin;

  std::cout << k << "-combinaison of a 100 set:" << std::endl;
  Cin = 1;
  for (int i = 0; i < k; i++)
    Cin = (long double)Cin * ((long double)n - (long double)i) / ((long double)i + 1.0);
  std::cout << std::fixed << std::setprecision(0) << Cin << std::endl;
  return (0);
}

int	calc(int d)
{
  struct timeval stop, start;
  long double	p = 3500.0;
  long double	x = (double)d / 8.0 / 3600.0;
  char		c;
  long double	overload;
  long double	lambda = (x * 3500.0);
  long double	Pn[51];

  std::cout << "Binomial distribution:" << std::endl;
  overload = 0.0;
  gettimeofday(&start, NULL);
  Pn[0] = (long double)pow((1.0 - (long double)x), (long double)p);
  for (int n = 1; n < 51; n++)
    Pn[n] = Pn[n - 1] * (p + 1.0 - (long double)n) / (long double)n * x / (1.0 - x);
  gettimeofday(&stop, NULL);
  std::cout << "0 -> " << std::fixed << std::setprecision(3) << Pn[0] << '\t';
  for (int n = 1; n < 51; n++)
    {
      c = '\t';
      if ((n + 1) % 6 == 0 || n == 50)
	c = '\n';
      if (n > 25)
	overload += Pn[n];
      std::cout << n << " -> " << std::fixed << std::setprecision(3) << Pn[n] << c;
    }
  overload *= 100;
  std::cout << "overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
  std::cout << "computation time: " << stop.tv_usec - start.tv_usec << " ms" << std::endl;
  std::cout << std::endl;

  gettimeofday(&start, NULL);
  Pn[0] = exp(-lambda);
  for (int n = 1; n <= 50; n++)
    Pn[n] = Pn[n - 1] * lambda / (long double)n;
  gettimeofday(&stop, NULL);
  std::cout << "Poisson distribution:" << std::endl;
  std::cout << "0 -> " << std::fixed << std::setprecision(3) << Pn[0] << '\t';
  overload = 0.0;
  for (int n = 1; n <= 50; n++)
    {
      c = '\t';
      if ((n + 1) % 6 == 0 || n == 50)
	c = '\n';
      if (n > 25)
	overload += Pn[n];
      std::cout << n << " -> " << std::fixed << std::setprecision(3) << Pn[n] << c;
    }
  overload *= 100;
  std::cout << "overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
  std::cout << "computation time: " << stop.tv_usec - start.tv_usec << " ms" << std::endl;
  return (0);
}
