import pandas as pd

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    df = employee.merge(department, left_on='departmentId', right_on='id', how='left')
    df = df[['name_y','name_x','salary']].copy()  # Keep Department, Employee, Salary
    df.columns = ['Department','Employee','Salary']
    
    # Rank salaries per department
    df['Rank'] = df.groupby('Department')['Salary'] \
                  .rank(method='dense', ascending=False)
    #sync
    # Keep top 3 per department
    top3 = df[df['Rank'] <= 3].sort_values(['Department','Rank'])
