#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6
/*
struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;
*/


void print_all_packages(town t) {
    char *town_name = t.name;//store name
    int office_cnt = t.offices_count;
    char ***package_name = (char***)malloc(office_cnt*sizeof(char**));//ith office jth package id
    for(int i=0;i<office_cnt;++i){
        int package_cnt = t.offices[i].packages_count;
        package_name[i] = (char**)malloc(package_cnt*sizeof(char*));
        for(int j=0;j<package_cnt;++j){
            package_name[i][j] = t.offices[i].packages[j].id;
        }
    }
    printf("%s:\n",town_name);
    for(int i=0;i<office_cnt;++i){
        printf("\t%d:\n",i);
        int package_cnt = t.offices[i].packages_count;
        for(int j=0;j<package_cnt;++j){
            printf("\t\t%s\n",package_name[i][j]);
        }
        free(package_name[i]);//deallocate
    }
    free(package_name);//deallocate
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int source_package_cnt = source->offices[source_office_index].packages_count;
    int target_min_weight = target->offices[target_office_index].min_weight;
    int target_max_weight = target->offices[target_office_index].max_weight;
    int remain_data = 0;
    int not_move_data = 0;
    package *remain_package = (package*)malloc(remain_data*sizeof(package));
    package *not_move = (package*)malloc(sizeof(package));
    for(int i=0;i<source_package_cnt;++i){
        int cur_weight = source->offices[source_office_index].packages[i].weight;
        if(cur_weight <= target_max_weight && cur_weight >= target_min_weight){
            remain_package[remain_data++] = source->offices[source_office_index].packages[i];
            remain_package = realloc(remain_package,(remain_data + 1)*sizeof(package));
        }
        else{
            not_move[not_move_data++] = source->offices[source_office_index].packages[i];
            not_move = realloc(not_move,sizeof(package)*(not_move_data + 1));
        }
    }
    int target_package_cnt = target->offices[target_office_index].packages_count;
    target->offices[target_office_index].packages_count = target_package_cnt + remain_data;
    target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages,sizeof(package)*(remain_data + target_package_cnt));
    for(int i=0;i<remain_data;++i) target->offices[target_office_index].packages[target_package_cnt + i] = remain_package[i];
    free(remain_package);
    source->offices[source_office_index].packages_count = not_move_data;
    source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages,not_move_data*sizeof(package));
    for(int i=0;i<not_move_data;++i) source->offices[source_office_index].packages[i] = not_move[i];
    free(not_move);
}

town town_with_most_packages(town* towns, int towns_count) {
    town ans;
    int *town_package_num = calloc(towns_count,sizeof(int));
    for(int i=0;i<towns_count;++i){
        int office_cnt = towns[i].offices_count;
        for(int j=0;j<office_cnt;++j){
            town_package_num[i] += towns[i].offices[j].packages_count;
        }
    }
    int index;
    int cmp = -1;
    for(int i=0;i<towns_count;++i){
        if(cmp < town_package_num[i]){
            cmp = town_package_num[i];
            index = i;
        }
    }
    free(town_package_num);
    return towns[index];
}

town* find_town(town* towns, int towns_count, char* name) {//towns[0]:{A} towns[1]:{B} towns_count = 2
    town* ans = malloc(sizeof(town));
    for(int i=0;i<towns_count;++i){
        if(strcmp(towns[i].name,name) == 0){
            ans = &towns[i];
            break;
        }
    }
    return ans;
}
/*
int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
*/