# 185. Department Top Three Salaries

**Category:** Pandas / SQL / Data Analysis  
**Difficulty:** Hard  

---

## Problem Description

Write a Pandas query to find the employees with the **top three highest unique salaries in each department**.  

You are given two DataFrames:

**Employee**  

| id | name  | salary | departmentId |
|----|-------|--------|--------------|

**Department**  

| id | name |
|----|------|

Return a DataFrame containing:

- Department name  
- Employee name  
- Salary  

Only include employees whose salary is in the **top three unique salaries** in their department.

---

## Example

**Input:**

```python
Employee = pd.DataFrame({
    'id': [1,2,3,4,5,6,7],
    'name': ['Joe','Henry','Sam','Max','Janet','Randy','Will'],
    'salary': [85000,80000,60000,90000,69000,85000,70000],
    'departmentId': [1,2,2,1,1,1,1]
})

Department = pd.DataFrame({
    'id': [1,2],
    'name': ['IT','Sales']
})
