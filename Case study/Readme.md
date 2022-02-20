DIGITAL CAMERA:
![image](https://user-images.githubusercontent.com/68070984/154844273-a0c75111-0b11-49f4-a427-d34382c27394.png)
A digital image is the product of three primary steps: optical image formation through lenses, light conversion to electrical signal, and image processing processes such as demosaicing, white balancing, noise removal, gamma curve correction, and so on. a whole set of documentation on computational photography is displayed. 
A block diagram of a typical imaging system is shown in Figure A system like this would include the following:

the image sensor, the optical lenses, and the colour filter array (CFA) (CCD, CMOS). It also contains the primary control.

Automatic gain control (AGC), analogue to digital converter (ADC), auto focus, and auto exposure circuitry are examples of such systems.

Color and digital image processing complete the digital signal path before it is sent.

Bayer color filter array:

      Single sensors have a major flaw in that they can only get one signal per photosite. A colour filter is overlaid on the sensor to introduce colour information. There are a variety of colour filter schemes available, with the most popular being the Bayer contract.

Design

• Unit cost: The monetary cost of producing each system copy, excluding NRE costs.

• Cost of NRE (Non-Recurring Engineering): Once upon a time

the expense of developing the system in terms of money

• Dimensions: the system's physical dimensions.

• System performance: the system's execution time or throughput.

• Power: the system's total power consumption.

• Flexibility: the capacity to alter the system's functionality.

system without having to pay a high NRE cost.


Requirements:

Low level requirements: 

• Efficiency: the amount of time it takes to process an image.
• Number of logic gates in the IC (2-input NAND gate)
• Power: a measure of the average amount of power used while processing.
• Energy: battery life (power x time)
       Metrics that are restricted
• Values must fall below (or occasionally exceed) a specified threshold.
       Metrics for optimization
• Made as many improvements as possible to the product
       Metrics can be limited as well as optimised.

High level Requirements:

•	Performance:
          The image must be processed quickly enough to be helpful.
1	second is a suitable time limit.
          Slower would be inconvenient, yet faster isn't required for the low-end of the market.
•	Size:
         Must use an IC that fits in a camera of reasonable size.
             200K gates are the constraint and optimization metric,     however lower is cheaper.
•	Power:
            It's necessary to keep the temperature below a specified level (no-cooling fan) a statistic that is restricted
•	Energy
             Reducing the amount of electricity or time used saves energy.
 Optimised metric: battery life should be as long as possible.


