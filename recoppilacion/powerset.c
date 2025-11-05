#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int check_int(char **str, int argc)
{
    int j = 1;
    while (j < argc)
    {
        int i = 0;
        if (str[j][i] == '-' || str[j][i] == '+')
            i++;
        while (str[j][i])
        {
            if (str[j][i] < '0' || str[j][i] > '9')
                return 0;
            i++;
        }
        j++;
    }
    return 1;
}

void solve(int *nums, int size, int target, int *subset, int index, int sub_size, int curr_sum)
{
	if(index == size){		
		if(curr_sum == target){
			for(int i =0; i < sub_size; i++){
				printf("%d", subset[i]);
				if(i != sub_size - 1)
					printf(" ");
			}
			printf("\n");
		}
		return ;
	}
	solve(nums, size, target, subset, index + 1, sub_size, curr_sum);
	subset[sub_size] = nums[index];
	solve(nums, size, target, subset, index + 1, sub_size + 1, curr_sum + nums[index]);
}

int main(int argc, char **argv)
{
	if(argc > 3 || check_int(argv, argc))
	{
		int target = atoi(argv[1]);
		int *nums = malloc(sizeof(int) * (argc - 2));
		for(int i= 0; i< argc -2; i++)
		{
			nums[i] = atoi(argv[i+2]);
		}
		int subset[(argc -2)];
		solve(nums, (argc -2), target, subset, 0, 0, 0);
		free(nums);	
		return 0;
	}
	return 1;
}
