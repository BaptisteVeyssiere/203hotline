//
// main.cpp for 202unsold in /home/scutar_n/rendu/maths
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 17:24:40 2017 Nathan Scutari
// Last update Wed Mar 22 12:02:05 2017 Nathan Scutari
//

#include <iostream>

int	proba(double, double);
int	calc(int);

int	write_help(void)
{
  std::cout << "USAGE" << std::endl << "\t\t./203hotline [n k | d]" << std::endl;
  std::cout << "DESCRIPION" << std::endl;
  std::cout << "\t\tn\tn value for the computation of" << std::endl;
  std::cout << "\t\tk\tk value for the computation of" << std::endl;
  std::cout << "\t\td\taverage duration of calls (in seconds)" << std::endl;
  return (0);
}

int	write_err(std::string error)
{
  std::cerr << error << std::endl;
  return (84);
}

int	getnbr(std::string arg, int arg_nbr)
{
  int	i;
  int	nbr;

  i = -1;
  while (arg[++i])
    if (arg[i] < '0' || arg[i] > '9')
      {
	std::cerr << "Error in arg: " << arg_nbr << " positive integer expected" << std::endl;
	return (-1);
      }
  nbr = std::stoi(arg);
  return (nbr);
}

int	main(int ac, char **av)
{
  std::string	arg;
  int		nbr1;
  int		nbr2;

  if (ac == 2)
    {
      arg = av[1];
      if (arg == "-h")
	return (write_help());
      if ((nbr1 = getnbr(av[1], 1)) == -1)
	return (84);
      return (calc(nbr1));
    }
  else if (ac == 3)
    {
      if ((nbr1 = getnbr(av[1], 1)) == -1 ||
	  (nbr2 = getnbr(av[2], 2)) == -1)
	return (84);
      return (proba(nbr1, nbr2));
    }
  else
    return (write_err("Invalid number of arguments\nType ./203hotline -h for help"));
  return (0);
}
