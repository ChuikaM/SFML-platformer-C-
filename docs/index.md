# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AdaptiveController`](#class_adaptive_controller) | Class that controlls temperature using Regulator & SimulatedModel.
`class `[`FactoryLinearModel`](#class_factory_linear_model) | Factory class that produces [NonLinearModel](#class_non_linear_model).
`class `[`FactoryNonLinearModel`](#class_factory_non_linear_model) | Factory class that produces [NonLinearModel](#class_non_linear_model).
`class `[`IFactoryModel`](#class_i_factory_model) | Interface for factory classes that produce simulated models.
`class `[`IRegulator`](#class_i_regulator) | Interface for regulator classes that controls temperature according to e(t) - deviation of the output variable y(t) from the desired value w(t).
`class `[`ISimulatedModel`](#class_i_simulated_model) | Interface for simulated models classes.
`class `[`LinearModel`](#class_linear_model) | Class for representing [LinearModel](#class_linear_model).
`class `[`NonLinearModel`](#class_non_linear_model) | Class for representing [NonLinearModel](#class_non_linear_model).
`class `[`PIDRegulator`](#class_p_i_d_regulator) | Class for representing [PIDRegulator](#class_p_i_d_regulator) that controls temperature according to e(t) - deviation of the output variable y(t) from the desired value w(t).

# class `AdaptiveController` 

Class that controlls temperature using Regulator & SimulatedModel.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`AdaptiveController`](#class_adaptive_controller_1a62bd4bb01fd167c59a67b9a67b7ca25c)`(std::unique_ptr< `[`IRegulator`](#class_i_regulator)` > regulator,std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > model)` | Default constructor for creating [AdaptiveController](#class_adaptive_controller).
`public inline std::vector< double > `[`run`](#class_adaptive_controller_1a495a1fe3e4231312f991e4b70d96b34b)`(const double w,const int t)` | Computes a vector of calculated temperatures & returns it according to w & t.

## Members

#### `public inline  explicit `[`AdaptiveController`](#class_adaptive_controller_1a62bd4bb01fd167c59a67b9a67b7ca25c)`(std::unique_ptr< `[`IRegulator`](#class_i_regulator)` > regulator,std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > model)` 

Default constructor for creating [AdaptiveController](#class_adaptive_controller).

#### Parameters
* `regulator` Copy of [IRegulator](#class_i_regulator) class. 

* `model` Copy of [ISimulatedModel](#class_i_simulated_model) class.

#### `public inline std::vector< double > `[`run`](#class_adaptive_controller_1a495a1fe3e4231312f991e4b70d96b34b)`(const double w,const int t)` 

Computes a vector of calculated temperatures & returns it according to w & t.

#### Parameters
* `w` Algorithm of system functioning. 

* `t` Time step at which vector of calculated temperatures is computed.

#### Returns
A vector of calculated temperatures.

# class `FactoryLinearModel` 

```
class FactoryLinearModel
  : public IFactoryModel
```  

Factory class that produces [NonLinearModel](#class_non_linear_model).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`FactoryLinearModel`](#class_factory_linear_model_1a23bcd741e15fb442a6200ecd2978e859)`() = default` | Default constructor.
`public  `[`~FactoryLinearModel`](#class_factory_linear_model_1a6fe62581142402290a1833338946788f)`() = default` | Virtual destructor for safe polymorphic usage.
`public inline virtual std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_factory_linear_model_1ac7ab9bc194d20f8835ba8a02812057f4)`() const` | Creates and returns a default [LinearModel](#class_linear_model).

## Members

#### `public  explicit `[`FactoryLinearModel`](#class_factory_linear_model_1a23bcd741e15fb442a6200ecd2978e859)`() = default` 

Default constructor.

#### `public  `[`~FactoryLinearModel`](#class_factory_linear_model_1a6fe62581142402290a1833338946788f)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public inline virtual std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_factory_linear_model_1ac7ab9bc194d20f8835ba8a02812057f4)`() const` 

Creates and returns a default [LinearModel](#class_linear_model).

#### Returns
A unique pointer to a newly created [LinearModel](#class_linear_model) instance.

# class `FactoryNonLinearModel` 

```
class FactoryNonLinearModel
  : public IFactoryModel
```  

Factory class that produces [NonLinearModel](#class_non_linear_model).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`FactoryNonLinearModel`](#class_factory_non_linear_model_1a443fdad0982aa8aef906787d7be20bac)`() = default` | Default constructor.
`public  `[`~FactoryNonLinearModel`](#class_factory_non_linear_model_1a2d24e63ec60337e62ee82c67ebc83da1)`() = default` | Virtual destructor for safe polymorphic usage.
`public inline virtual std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_factory_non_linear_model_1a6378a67bacb2a8da165505e30af54a77)`() const` | Creates and returns a default [NonLinearModel](#class_non_linear_model).

## Members

#### `public  explicit `[`FactoryNonLinearModel`](#class_factory_non_linear_model_1a443fdad0982aa8aef906787d7be20bac)`() = default` 

Default constructor.

#### `public  `[`~FactoryNonLinearModel`](#class_factory_non_linear_model_1a2d24e63ec60337e62ee82c67ebc83da1)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public inline virtual std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_factory_non_linear_model_1a6378a67bacb2a8da165505e30af54a77)`() const` 

Creates and returns a default [NonLinearModel](#class_non_linear_model).

#### Returns
A unique pointer to a newly created [NonLinearModel](#class_non_linear_model) instance.

# class `IFactoryModel` 

Interface for factory classes that produce simulated models.

This abstract class defines a contract for creating default instances of [ISimulatedModel](#class_i_simulated_model).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~IFactoryModel`](#class_i_factory_model_1a7b24bb494392e77d08b96af111965641)`() = default` | Virtual destructor for safe polymorphic usage.
`public std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_i_factory_model_1af4826f947c2625646f3a900693ac0644)`() const` | Creates and returns a default simulated model.

## Members

#### `public virtual  `[`~IFactoryModel`](#class_i_factory_model_1a7b24bb494392e77d08b96af111965641)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public std::unique_ptr< `[`ISimulatedModel`](#class_i_simulated_model)` > `[`getDefaultModel`](#class_i_factory_model_1af4826f947c2625646f3a900693ac0644)`() const` 

Creates and returns a default simulated model.

#### Returns
A unique pointer to a newly created [ISimulatedModel](#class_i_simulated_model) instance.

# class `IRegulator` 

Interface for regulator classes that controls temperature according to e(t) - deviation of the output variable y(t) from the desired value w(t).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~IRegulator`](#class_i_regulator_1ac6599b2211b5fac7ec1c1f24aa4c3f95)`() = default` | Virtual destructor for safe polymorphic usage.
`public double `[`step`](#class_i_regulator_1a8c7903b82d0442db2ca8274bcc4e8259)`(double e,double t)` | Calculate next u - input warm according to e & t - and returns it.

## Members

#### `public virtual  `[`~IRegulator`](#class_i_regulator_1ac6599b2211b5fac7ec1c1f24aa4c3f95)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public double `[`step`](#class_i_regulator_1a8c7903b82d0442db2ca8274bcc4e8259)`(double e,double t)` 

Calculate next u - input warm according to e & t - and returns it.

#### Parameters
* `e` Deviation of the output variable y(t) from the desired value w(t). 

* `t` Time step at which u is computed.

#### Returns
u - Input warm.

# class `ISimulatedModel` 

Interface for simulated models classes.

This abstract class defines a way to calculate next temperature (y) according to the model's formula.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~ISimulatedModel`](#class_i_simulated_model_1a633bd4274072567356203c7f624e464e)`() = default` | Virtual destructor for safe polymorphic usage.
`public double `[`step`](#class_i_simulated_model_1a69e2339060948388fee8280701baf9c3)`(const double u)` | Calculates next temperature (y) according to the model's formula and returns it.
`public std::vector< double > `[`simulate`](#class_i_simulated_model_1a971060b31948ccad0ca2fa06c46b3e21)`(double y,const double u,int t)` | Computes a vector of calculated temperatures & returns it according to y, u, t.

## Members

#### `public virtual  `[`~ISimulatedModel`](#class_i_simulated_model_1a633bd4274072567356203c7f624e464e)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public double `[`step`](#class_i_simulated_model_1a69e2339060948388fee8280701baf9c3)`(const double u)` 

Calculates next temperature (y) according to the model's formula and returns it.

#### Parameters
* `u` Input warm.

#### Returns
Calculated next temperature (y).

#### `public std::vector< double > `[`simulate`](#class_i_simulated_model_1a971060b31948ccad0ca2fa06c46b3e21)`(double y,const double u,int t)` 

Computes a vector of calculated temperatures & returns it according to y, u, t.

#### Parameters
* `y` Initial temperature. 

* `u` Input warm. 

* `t` Time step at which vector of calculated temperatures is computed.

#### Returns
A vector of calculated temperatures.

# class `LinearModel` 

```
class LinearModel
  : public ISimulatedModel
```  

Class for representing [LinearModel](#class_linear_model).

This class defines a way to calculate next temperature (y) according to it's formula.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`LinearModel`](#class_linear_model_1a4418d08b99107d0bd6060a1111b7ff93)`(const double a,const double b)` | Default constructor for creating [LinearModel](#class_linear_model).
`public  `[`~LinearModel`](#class_linear_model_1a4a9d9e4e2ce4e51ed5a1e70aebdece31)`() = default` | Virtual destructor for safe polymorphic usage.
`public inline virtual double `[`step`](#class_linear_model_1aba1755b56686d7e84c5a3180c082f5aa)`(const double u)` | Calculates next temperature (y).
`public inline virtual std::vector< double > `[`simulate`](#class_linear_model_1a5416ffa606a5a9b75beb3c33536bf410)`(double y,const double u,int t)` | Computes a vector of calculated temperatures & returns it according to y, u, t.

## Members

#### `public inline  explicit `[`LinearModel`](#class_linear_model_1a4418d08b99107d0bd6060a1111b7ff93)`(const double a,const double b)` 

Default constructor for creating [LinearModel](#class_linear_model).

#### Parameters
* `a` Linear coefficient for previous output (y). 

* `b` Linear coefficient for input (u).

#### `public  `[`~LinearModel`](#class_linear_model_1a4a9d9e4e2ce4e51ed5a1e70aebdece31)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public inline virtual double `[`step`](#class_linear_model_1aba1755b56686d7e84c5a3180c082f5aa)`(const double u)` 

Calculates next temperature (y).

Formula for the next temperature (y):   
$$
\Large y_{\tau+1} = a y_{\tau} + b u_{\tau}
$$

#### Parameters
* `u` Input warm.

#### Returns
Calculated next temperature (y).

#### `public inline virtual std::vector< double > `[`simulate`](#class_linear_model_1a5416ffa606a5a9b75beb3c33536bf410)`(double y,const double u,int t)` 

Computes a vector of calculated temperatures & returns it according to y, u, t.

#### Parameters
* `y` Initial temperature. 

* `u` Input warm. 

* `t` Time step at which vector of calculated temperatures is computed.

#### Returns
A vector of calculated temperatures.

# class `NonLinearModel` 

```
class NonLinearModel
  : public ISimulatedModel
```  

Class for representing [NonLinearModel](#class_non_linear_model).

This class defines a way to calculate next temperature (y) according to it's formula.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`NonLinearModel`](#class_non_linear_model_1a07009f707dce40107dea8941ccec2e5d)`(const double a,const double b,const double c,const double d)` | Default constructor for creating [NonLinearModel](#class_non_linear_model).
`public  `[`~NonLinearModel`](#class_non_linear_model_1ac558b1556d769c4fee9261ce77ef7f3b)`() = default` | Virtual destructor for safe polymorphic usage.
`public inline virtual double `[`step`](#class_non_linear_model_1ad79cbedb8375089a86fb54172e4a6966)`(const double u)` | Calculates next temperature (y).
`public inline virtual std::vector< double > `[`simulate`](#class_non_linear_model_1ac4ec5911cf8264c0a7bc00fb107c1685)`(double y,const double u,int t)` | Computes a vector of calculated temperatures & returns it according to y, u, t.

## Members

#### `public inline  explicit `[`NonLinearModel`](#class_non_linear_model_1a07009f707dce40107dea8941ccec2e5d)`(const double a,const double b,const double c,const double d)` 

Default constructor for creating [NonLinearModel](#class_non_linear_model).

#### Parameters
* `a` Nonlinear coefficient for current output (y). 

* `b` Nonlinear coefficient for squared previous output (prevY²). 

* `c` Nonlinear coefficient for input (u). 

* `d` Nonlinear coefficient for sinusoidal input term.

#### `public  `[`~NonLinearModel`](#class_non_linear_model_1ac558b1556d769c4fee9261ce77ef7f3b)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public inline virtual double `[`step`](#class_non_linear_model_1ad79cbedb8375089a86fb54172e4a6966)`(const double u)` 

Calculates next temperature (y).

Formula for the next temperature (y):   
$$
\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})
$$

#### Parameters
* `u` Input warm.

#### Returns
Calculated next temperature (y).

#### `public inline virtual std::vector< double > `[`simulate`](#class_non_linear_model_1ac4ec5911cf8264c0a7bc00fb107c1685)`(double y,const double u,int t)` 

Computes a vector of calculated temperatures & returns it according to y, u, t.

#### Parameters
* `y` Initial temperature. 

* `u` Input warm. 

* `t` Time step at which vector of calculated temperatures is computed.

#### Returns
A vector of calculated temperatures.

# class `PIDRegulator` 

```
class PIDRegulator
  : public IRegulator
```  

Class for representing [PIDRegulator](#class_p_i_d_regulator) that controls temperature according to e(t) - deviation of the output variable y(t) from the desired value w(t).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`PIDRegulator`](#class_p_i_d_regulator_1adeda86734b2d5e96b136c663e723c9d4)`()` | Default constructor.
`public  `[`~PIDRegulator`](#class_p_i_d_regulator_1a6f39514e801f944a6cf7e06ac7c40254)`() = default` | Virtual destructor for safe polymorphic usage.
`public inline virtual double `[`step`](#class_p_i_d_regulator_1aa530c53c060a2a00bcf5c77e2ad33367)`(double e,double t)` | Calculate next u - input warm according to e & t - and returns it.

## Members

#### `public inline  explicit `[`PIDRegulator`](#class_p_i_d_regulator_1adeda86734b2d5e96b136c663e723c9d4)`()` 

Default constructor.

#### `public  `[`~PIDRegulator`](#class_p_i_d_regulator_1a6f39514e801f944a6cf7e06ac7c40254)`() = default` 

Virtual destructor for safe polymorphic usage.

#### `public inline virtual double `[`step`](#class_p_i_d_regulator_1aa530c53c060a2a00bcf5c77e2ad33367)`(double e,double t)` 

Calculate next u - input warm according to e & t - and returns it.

Formula:   
$$
u(k) = u(k - 1) + \Delta u(k)
$$

$$
\Delta u(k) = q_1 e(k) + q_2 e(k - 1) + q_3 e(k - 2)
$$

$$
q_0 = K \left( 1 + \frac{T_D}{T_0} \right)
$$

$$
q_1 = -K \left( 1 + 2 \frac{T_D}{T_0} - \frac{T_0}{T} \right)
$$

$$
q_2 = K \frac{T_D}{T_0}
$$

#### Parameters
* `e` Deviation of the output variable y(t) from the desired value w(t). 

* `t` Time step at which u is computed.

#### Returns
u - Input warm.

Generated by [Moxygen](https://sourcey.com/moxygen)