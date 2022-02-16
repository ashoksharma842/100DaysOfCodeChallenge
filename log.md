# 100 Days Of Code - Log

### Day 1: 08-02-2022

**Today's Progress**: setup for development, testing file size and memories of NUC240 microcontroller,

**Thoughts:** Tried to visualize data in memory view. 
Viewing RAM was easy but it took time to reflact the memory in flash.

**Link to work:** none

### Day 2: 09-02-2022

**Today's Progress**: I2C communication failed to initiate.

**Thoughts:** I tried to do I2C communication but initialization failed.
Also I accidently deleted the day1 folder, so I have to get that back from git.
Figuring that out also took some time.

### Day 3: 10-02-2022

**Today's Progress**: I2C communication configuration.

**Thoughts:** I2C configurated to 100kbps.
The datasheet says config MFP, enable clock and then reset module for initialization.
Speed was not getting set. Found a way to look into the peripharal registers in eclipse.
After some time got to know that reset module stops it.
After skipping the reset step, I2C configured properly.

### Day 4: 11-02-2022

**Today's Progress**: I2C master coded for nuvoton. testing is pending.

**Thoughts:** To test i2c master I will make a i2c slave from esp32.
A new folder/repo is made for loggin progress. So it can be seen on git hub.
For now just copied the code files and not the whole project.

### Day 5: 14-02-2022

**Today's Progress**: Read baromatric pressure sensor's ID using I2C.

**Thoughts:** To confirm the working of Sensor, first sensor is tested with
standard arduino code with esp32. It was working fine.
Then the I2C read code (bare metal) was made on Nuvoton.

### Day 6: 15-02-2022

**Today's Progress**: Tried I2C communication with interrupt.

**Thoughts:** I2C remains stuck in interrupt. There is no wey to clear the interrupt.
Will investigate how the example codes get out of interrupt tomorrow and implement that.

### Day 7: 16-02-2022

**Today's Progress**: Tried I2C communication with esp32.

**Thoughts:** setup for idf took time. To run menuconfig on VS PIO was difficult.
tested the example code from koblan, worked ok after few trials.
The i2c struct needs to be initialized to zero in order to work.
also the pin numbers of mudule are confusing.
