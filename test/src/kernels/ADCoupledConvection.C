//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ADCoupledConvection.h"

registerADMooseObject("MooseTestApp", ADCoupledConvection);

template <ComputeStage compute_stage>
InputParameters
ADCoupledConvection<compute_stage>::validParams()
{
  InputParameters params = ADKernel<compute_stage>::validParams();
  params.addParam<Real>("scale", 1, "Scaling coefficient");
  params.addRequiredCoupledVar("velocity_vector", "Velocity Vector for the Convection ADKernel");
  return params;
}

template <ComputeStage compute_stage>
ADCoupledConvection<compute_stage>::ADCoupledConvection(const InputParameters & parameters)
  : ADKernel<compute_stage>(parameters),
    _velocity_vector(adCoupledGradient("velocity_vector")),
    _scale(getParam<Real>("scale"))
{
}

template <ComputeStage compute_stage>
ADReal
ADCoupledConvection<compute_stage>::computeQpResidual()
{
  return _scale * _test[_i][_qp] * _velocity_vector[_qp] * _grad_u[_qp];
}
