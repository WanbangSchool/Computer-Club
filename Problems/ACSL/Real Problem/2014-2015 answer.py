citySwitch = "ABCDEFG"
distances = [450,140,120,320,250,80]
result1 = []
result2 = []
result3 = []

milesPerGallon, pricePerGallon, averageSpeed = input().split()

for i in range(4):
    startingCity, endCity = input().split()
    totalMiles = sum(distances[citySwitch.find(startingCity):citySwitch.find(endCity)])
    result1.append(totalMiles)
    totalHour = int(totalMiles / float(averageSpeed))
    totalMin = int((totalMiles / float(averageSpeed) - totalHour)*60)
    result2.append(str(totalHour).zfill(2)+":"+str(totalMin).zfill(2))
    result3.append(float(pricePerGallon) * totalMiles / float(milesPerGallon))

for i in range(4):
    print(result1[i],result2[i],"${:.2f}".format(result3[i]))