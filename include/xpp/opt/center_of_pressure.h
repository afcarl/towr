/**
 @file    center_of_pressure.h
 @author  Alexander W. Winkler (winklera@ethz.ch)
 @date    Mar 16, 2017
 @brief   Brief description
 */

#ifndef XPP_XPP_OPT_INCLUDE_XPP_OPT_CENTER_OF_PRESSURE_H_
#define XPP_XPP_OPT_INCLUDE_XPP_OPT_CENTER_OF_PRESSURE_H_

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <xpp/cartesian_declarations.h>
#include <xpp/parametrization.h>

namespace xpp {
namespace opt {

/** Parametrizes the motion of the center of pressure over the trajectory.
  *
  * In this case we discretize and represent as piece-wise constant.
  */
class CenterOfPressure : public Parametrization {
public:
  using VectorXd = Eigen::VectorXd;
  using Vector2d = Eigen::Vector2d;
  using JacobianRow = Eigen::SparseVector<double, Eigen::RowMajor>;

  CenterOfPressure ();
  virtual ~CenterOfPressure ();

  void Init(double dt, double T);

  void SetOptimizationParameters(const VectorXd& x) override;
  VectorXd GetOptimizationParameters() const override;
  int Index(double t, d2::Coords dimension) const;

  Vector2d GetCop(double t) const;
  JacobianRow GetJacobianWrtCop(double t, d2::Coords dim) const;

private:
  VectorXd cop_;
  double dt_;

  int GetSegment (double t) const;
};

} /* namespace opt */
} /* namespace xpp */

#endif /* XPP_XPP_OPT_INCLUDE_XPP_OPT_CENTER_OF_PRESSURE_H_ */