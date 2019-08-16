# teensy_adc_tips
Some example code and info regarding the Teensy 3.6 and how to send ADC readings over serial. 

# Folder Structure:

Arduino sketches:
- adc_benchmark: Send different commands to the teensy to compare the speed of different sampling approaches. 
- adc_minimal_block_convert: A trimmed down version of https://github.com/uutzinger/TeensyDMA_ADC_server. Send one command ('c') to initiate a conversion (sampled the ADC a specified sample rate until the buffer is full), send another command ('p') to print the buffer over serial. Makes it easy to add your own commands, and is a god starting point for single channel sampling. 

Docs:
- Reading Serial Data
- Benchmark Results

Jupyter Notebooks:
- Benchmark: Communicates with the benchmarking sketch over serial, demonstrating how to set up serial communication in Python (can be adapted for other languages).
- Block Convert: Shows communication with the second sketch (adc_minimal_block_convert) to read the ADC as fast as possible.

Useful links:
- A good example of streaming data over serial (plus DMA config etc): https://github.com/uutzinger/TeensyDMA_ADC_server
- The Teensy forums: https://forum.pjrc.com
- The technical datasheets: https://www.pjrc.com/teensy/datasheets.html
- App note on multi-channel sampling (will require some creativity to implement): https://www.nxp.com/docs/en/application-note/AN4590.pdf

Other things mentioned in the lecture:
- My thesis project:
    Report: https://github.com/johnowhitaker/cirts
    Video: https://www.youtube.com/watch?v=fFSetleTe_o
    Hackaday Project (has a few updates): https://hackaday.io/project/162352-cirts-configurable-infra-red-tomography-systems
- The new Teensy 4.0: https://www.pjrc.com/store/teensy40.html
- Ben Krasnow (Applied Science chanel): https://www.youtube.com/user/bkraz333

