##### Authors:
Avichay Nega, [Omer Hadida](https://github.com/2MarShmello2), [Oren Zauda](https://github.com/OrenZauda)

# Physical Number Conversion

In this task, we were asked to focus on the three dimensions of Newtonian physics: length, time, and mass.

## Usage

We were asked to write a department representing a number with units.
In this class it is possible, for example, to represent the number "3 meters" and the number "40 centimeters", and their sum is not
Will be 43 but 4.3 meters - the department will make sure to perform the appropriate conversion.
In addition, the department will not allow a member
Numbers with incompatible dimensions, for example, connecting "3 meters" with "5 seconds" will cause an exception.

### Units of measurement:

**Length**
   - centimeter
     - [cm]
   - meter
      - [m]
   - kilometer
      - [km]
      
**Time**
   - seconds
     - [sec]
   - minuts
      - [min]
   - hours
      - [hour]
      
**Mass**
   - gram
     - [g]
   - kilogram
      - [kg]
   - ton
      - [ton]
      
## Example

test code:

```c++
 PhysicalNumber a(2, Unit::KM);
 PhysicalNumber b(300, Unit::M);
 
 .CHECK_OUTPUT(a+b, "2.3[km]")
```

output:

```c++
 2.3[km]
```
      
### Our mentor

[Erel Segal-Halevi](https://github.com/erelsgl/ariel-cpp-5779) 


