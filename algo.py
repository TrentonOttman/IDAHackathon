component_assignments = {
    'Station 1': 'CC',
    'Station 2': 'CE',
    'Station 3': 'CA',
    'Station 4': 'CB',
    'Station 5': 'CD',
}

inventory_allocations = {
    'CA1': 15, 'CA2': 12, 'CA3': 7, 'CA4': 15, 'CA5': 9, 'CA6': 15, 'CA7': 12, 'CA8': 15,
    'CB1': 17, 'CB2': 58, 'CB3': 25,
    'CC1': 5, 'CC2': 21, 'CC3': 10, 'CC4': 16, 'CC5': 12, 'CC6': 19, 'CC7': 17,
    'CD1': 8, 'CD2': 17, 'CD3': 35, 'CD4': 5, 'CD5': 21, 'CD6': 14,
    'CE1': 4, 'CE2': 6, 'CE3': 11, 'CE4': 5, 'CE5': 4, 'CE6': 17, 'CE7': 12, 'CE8': 18, 'CE9': 23,
}
best_value = 0
best_sum = 0

for i in range(15):
  reorder_points = {
    'CA1': i, 'CA2': 7, 'CA3': 3, 'CA4': 9, 'CA5': 4, 'CA6': 9, 'CA7': 6, 'CA8': 10,
    'CB1': 7, 'CB2': 39, 'CB3': 13,
    'CC1': 1, 'CC2': 14, 'CC3': 4, 'CC4': 9, 'CC5': 6, 'CC6': 12, 'CC7': 10,
    'CD1': 3, 'CD2': 10, 'CD3': 24, 'CD4': 0, 'CD5': 13, 'CD6': 8,
    'CE1': 1, 'CE2': 3, 'CE3': 7, 'CE4': 1, 'CE5': 1, 'CE6': 11, 'CE7': 7, 'CE8': 12, 'CE9': 15,
}
  simulation_metrics = run_simulation(
    production_data=data,
    component_assignments=component_assignments,
    inventory_allocations=inventory_allocations,
    reorder_points=reorder_points,
    num_handlers=1,
    day_start=1,
    day_end=90,
    space_available=100,
)
  if simulation_metrics['Total_costs'].sum() > best_sum:
    best_value = i
    best_sum = simulation_metrics['Total_costs'].sum()

print(best_sum)
print(best_value)


## dict syntax
    hashmap = {"a":20,"b":30}
    res = ''
    maxVal = 0
    for i in hashmap.keys():
        if hashmap[i] > maxVal:
            maxVal = hashmap[i]
            res = i
    print(i)
