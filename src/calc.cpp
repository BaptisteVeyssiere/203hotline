//
// calc.cpp for Project-Master in /home/veyssi_b/rendu/tek2/Math/203hotline
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Mar 13 16:24:31 2017 Baptiste Veyssiere
// Last update Mon Mar 13 18:29:37 2017 Baptiste Veyssiere
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
    Cin *= (n - (double)i) / ((double)i + 1.0);
  std::cout << std::fixed << std::setprecision(0) << Cin << std::endl;
}

int	calc(int d)
{
  struct timeval stop, start;
  double	p = 3500.0;
  double	x = (double)d / 8.0 / 3600.0;
  char		c;
  double	overload;
  double	lambda = (x * 3500.0);
  double	Pn[51];

  std::cout << "Binomial distribution:" << std::endl;
  overload = 0.0;
  gettimeofday(&start, NULL);
  Pn[0] = (double)pow((1 - x), p);
  for (int n = 1; n < 51; n++)
    Pn[n] = Pn[n - 1] * (p + 1.0 - (double)n) / (double)n * x / (1 - x);
  gettimeofday(&stop, NULL);
  std::cout << "0->" << std::fixed << std::setprecision(3) << Pn[0] << '\t';
  for (int n = 1; n < 51; n++)
    {
      c = '\t';
      if ((n + 1) % 6 == 0 || n == 50)
	c = '\n';
      if (n > 25)
	overload += Pn[n];
      std::cout << n << "->" << std::fixed << std::setprecision(3) << Pn[n] << c;
    }
  overload *= 100;
  std::cout << "overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
  std::cout << "computation time: " << stop.tv_usec - start.tv_usec << " ms" << std::endl;
  std::cout << std::endl;

  gettimeofday(&start, NULL);
  Pn[0] = exp(-lambda);
  for (int n = 1; n <= 50; n++)
    Pn[n] = Pn[n - 1] * lambda / (double)n;
  gettimeofday(&stop, NULL);
  std::cout << "Poisson distribution:" << std::endl;
  std::cout << "0->" << std::fixed << std::setprecision(3) << Pn[0] << '\t';
  overload = 0.0;
  for (int n = 1; n <= 50; n++)
    {
      c = '\t';
      if ((n + 1) % 6 == 0 || n == 50)
	c = '\n';
      if (n > 25)
	overload += Pn[n];
      std::cout << n << "->" << std::fixed << std::setprecision(3) << Pn[n] << c;
    }
  overload *= 100;
  std::cout << "overload: " << std::fixed << std::setprecision(1) << overload << "%" << std::endl;
  std::cout << "computation time: " << stop.tv_usec - start.tv_usec << " ms" << std::endl;
  return (0);
}