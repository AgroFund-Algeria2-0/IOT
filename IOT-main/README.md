## AGRO FUND DZ :

## Project Overview

This IoT-based smart irrigation system is designed for the AgroFund DZ platform, connecting investors with farmers through transparent and efficient agricultural solutions. The system uses multiple DHT22 sensors to monitor environmental conditions across different areas of a farm and automatically controls irrigation pumps based on temperature and humidity levels.

[View the project on Wokwi](https://wokwi.com/projects/448904747240216577)

## System Functionality

### Circuit Components:
- 1x ESP32 microcontroller (the system's brain)
- 3x DHT22 sensors for monitoring temperature and humidity in different farm zones
- 3x Water pumps (one for each sensor zone)
- 3x Indicator LEDs to show pump status
- 1x serial monitor
- 
### How It Works:
1. Each DHT22 sensor monitors temperature and humidity in its designated farm zone
2. When temperature rises above 30°C and humidity falls below 40% in a zone, the corresponding pump activates
3. The system continuously monitors all three zones independently
4. Indicator LEDs show which pumps are active
5. Sensor data is transmitted to a remote dashboard for monitoring

## Benefits for Investors

### Transparency and Trust
- Real-time monitoring of farming activities ensures investment is being used properly
- Investors can verify that their equipment is actually being deployed and operated
- Data logs provide evidence of active farm management

### Risk Reduction
- Early detection of unfavorable conditions prevents crop losses
- Automated irrigation prevents under-watering that could damage crops
- Remote monitoring allows for quick intervention if problems arise

### ROI Verification
- Detailed data analytics show how investments are performing
- Irrigation patterns help verify farming progress
- Environmental data correlates with expected crop yields

## Benefits for Farmers

### Resource Optimization
- Water is used efficiently, only when and where needed
- Prevents both under-watering and over-watering
- Reduces manual labor for irrigation management

### Crop Protection
- Maintains optimal growing conditions in each farm zone
- Prevents crop stress from extreme temperature or humidity
- Automated system acts faster than manual intervention

### Data-Driven Decisions
- Historical environmental data helps optimize farming practices
- Zone-specific monitoring allows for targeted interventions
- Provides evidence of proper farm management to investors

## Cost Efficiency and Practicality

### Low Hardware Costs
- **ESP32 microcontroller**: ~$8 each
- **DHT22 sensors**: ~$5 each (3 sensors = ~$15)
- **Water pumps**: ~$15 each (3 pumps = ~$45)
- **Additional components**: ~$10
- **Total system cost**: ~$78 for comprehensive 3-zone monitoring

### Implementation Advantages
- **Wireless connectivity**: No complex wiring needed between zones
- **Solar compatible**: Low power consumption allows for solar power setup
- **Scalable**: Additional zones can be added with minimal cost per zone
- **Minimal maintenance**: Few components with proven reliability

### Return on Investment
- **Water savings**: 30-50% reduction in irrigation waste compared to manual systems
- **Labor savings**: Reduced need for manual watering and monitoring
- **Crop yield improvement**: Maintained optimal growing conditions lead to better yields
- **Faster deployment**: Simple installation process compared to traditional irrigation systems

## Technical Implementation

The system uses threshold-based logic to activate irrigation:
- Temperature threshold: Above 30°C
- Humidity threshold: Below 40%
- Each zone operates independently, allowing for microclimate management
- Remote monitoring via cloud dashboard provides real-time data access
