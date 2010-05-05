#ifndef COEFDIFFUSION_H
#define COEFDIFFUSION_H

#include "Kernel.h"

//Forward Declarations
class CoefDiffusion;

template<>
InputParameters validParams<CoefDiffusion>();

class CoefDiffusion : public Kernel
{
public:

  CoefDiffusion(std::string name, MooseSystem & moose_system, InputParameters parameters);

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

private:
  Real _coef;
};
#endif //COEFDIFFUSION_H
