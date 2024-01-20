'''
generated using chat gpt 3.5 and tweked a bit
'''

import random
from datetime import datetime, timedelta

# Function to generate random data for 365 days
def generate_random_data():
    start_date = datetime(2024, 1, 1)
    end_date = start_date + timedelta(days=364)

    with open('dummy_data.csv', 'w') as file:
        file.write('date,energylevel,onlycardio\n')

        current_date = start_date
        while current_date <= end_date:
            value1 = random.randint(0, 5)
            value2 = random.randint(0, 1)
            file.write(f'{current_date.strftime("%Y-%m-%d")},{value1},{value2}\n')

            current_date += timedelta(days=1)

if __name__ == "__main__":
    generate_random_data()
