#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaring the functions
void file_scanner();
void file_data_printer();
void total_gpa_analyzer();
void ssc_gpa_analyzer();
void hsc_gpa_analyzer();
float *delete_duplicate_element(float*,int);
float *sort_decreasing_order(float*,int);

// array for storing data of students attributes
float total_gpa_arr[20];
float hsc_gpa_arr[20];
float ssc_gpa_arr[20];

float *total_gpa_array_modified;
float *ssc_gpa_array_modified;
float *hsc_gpa_array_modified;

// declared them as globals for changing at ease an using at any place of codes
int number_of_students   = 5;  //! Enter the number of student data you want to enter
int number_of_attributes = 5;

//variable that stores unique gpa 
int unique_total_gpa;
int unique_hsc_gpa;
int unique_ssc_gpa;

//strucure to store the ta data
struct details {
    int id ;
    char name [10];
    float total_gpa;
    float hsc_gpa;
    float ssc_gpa;

} details [20];

//strucure to store the ta attributes
struct string_details{
    char id [10];
    char name [10];
    char total_gpa[10];
    char hsc_gpa[10];
    char ssc_gpa[10];
} string [20];


// a function to scan the data  
void file_scanner()
{
    FILE *student_file = fopen ("student_data.txt", "r");

     for (int i = 0; i < number_of_students ; i++){
            for(int j = 0 ; j < number_of_attributes ; j ++ )
            {
                 switch (j) {
                    case 0:     fscanf(student_file, "%s %d", &string[i].id,&details[i].id);
                                break;

                    case 1:     fscanf(student_file, "%s %s", &string[i].name,&details[i].name);
                                break;
                    
                    case 2:     fscanf(student_file, "%s %f", &string[i].total_gpa,&details[i].total_gpa);
                                total_gpa_arr[i] = details[i].total_gpa;
                                break;
                    
                    case 3:     fscanf(student_file, "%s %f", &string[i].hsc_gpa,&details[i].hsc_gpa);
                                hsc_gpa_arr[i] = details[i].hsc_gpa;
                                break;
                    
                    case 4:     fscanf(student_file, "%s %f", &string[i].ssc_gpa,&details[i].ssc_gpa);
                                ssc_gpa_arr[i] = details[i].ssc_gpa;
                                break;

                    default:
                                break;
                            }
            }
        }
        fclose(student_file); 
}

// function to print the data of the students 
void file_data_printer()
{
    for (int i =0 ; i < number_of_students ; i ++)
    {
        printf ("%s\t\t%d\n",string[i].id,details[i].id);
        printf ("%s\t\t%s\n",string[i].name,details[i].name);
        printf ("%s\t%.2f\n",string[i].total_gpa,details[i].total_gpa);
        printf ("%s\t\t%.2f\n",string[i].hsc_gpa,details[i].hsc_gpa);
        printf ("%s\t\t%.2f\n\n",string[i].ssc_gpa,details[i].ssc_gpa);
        
    }
}

// a function that will print out the data of total_gpa in different places
void total_gpa_analyzer(){

    FILE *total_file = fopen("total_gpa_analysis.txt","w");   //opening the files in read and appending mode
    FILE *student_file = fopen("student_data.txt","a");

    for (int i =0 ; i < unique_total_gpa ; i ++)
        {
            fprintf(total_file,"Total GPA : %.2f\n",total_gpa_array_modified[i]);     //three printf 1.for writing 2. for appending 3. for console
            fprintf(student_file,"Total GPA : %.2f\n",total_gpa_array_modified[i]);
            printf("Total GPA : %.2f\n",total_gpa_array_modified[i]);

            fprintf(total_file,"================\n");
            fprintf(student_file,"================\n");
            printf("================\n");

            for (int j = 0 ; j <number_of_students ;j ++  )
            {    
                 if (total_gpa_array_modified[i] == details[j].total_gpa){           //checking if the value of the array is matching with any student data
                     fprintf(total_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     fprintf(student_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     printf("ID : %d   Name:%s\n",details[j].id,details[j].name);
                 }
            }
            fprintf(total_file,"\n\n");
            fprintf(student_file,"\n\n");
            printf("\n\n");   
        }
}

// a function that will print out the data of ssc in different places
void ssc_gpa_analyzer(){    

    FILE *ssc_file = fopen("ssc_gpa_analysis.txt","w");  //opening the files in read and appending mode
    FILE *student_file = fopen("student_data.txt","a");

     for (int i =0 ; i < unique_ssc_gpa ; i ++)
        {
            fprintf(ssc_file,"SSC GPA : %.2f\n",ssc_gpa_array_modified[i]);             //three printf 1.for writing 2. for appending 3. for console
            fprintf(student_file,"SSC GPA : %.2f\n",ssc_gpa_array_modified[i]);
            printf("SSC GPA : %.2f\n",ssc_gpa_array_modified[i]);

            fprintf(ssc_file,"================\n");
            fprintf(student_file,"================\n");
            printf("================\n");

            for (int j = 0 ; j <number_of_students ;j ++  )
            {  
                 if (ssc_gpa_array_modified[i] == details[j].ssc_gpa){     //checking if the value of the array is matching with any student data
                     fprintf(ssc_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     fprintf(student_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     printf("ID : %d   Name:%s\n",details[j].id,details[j].name);
                 }
            }
            fprintf(ssc_file,"\n\n");
            fprintf(student_file,"\n\n");
            printf("\n\n"); 
        }
}

// a function that will print out the data of hsc in different places
void hsc_gpa_analyzer(){     

    FILE *hsc_file = fopen("hsc_gpa_analysis.txt","w"); //opening the files in read and appending mode
    FILE *student_file = fopen("student_data.txt","a");

    for (int i =0 ; i < unique_hsc_gpa ; i ++)
        {
            fprintf(hsc_file,"HSC GPA : %.2f\n",hsc_gpa_array_modified[i]);      //three printf 1.for writing 2. for appending 3. for console
            fprintf(student_file,"HSC GPA : %.2f\n",hsc_gpa_array_modified[i]);
            printf("HSC GPA : %.2f\n",hsc_gpa_array_modified[i]);

            fprintf(hsc_file,"================\n");
            fprintf(student_file,"================\n");
            printf("================\n");

            for (int j = 0 ; j <number_of_students ;j ++  )
            {      
                 if (hsc_gpa_array_modified[i] == details[j].hsc_gpa){                  //checking if the value of the array is matching with any student data
                     fprintf(hsc_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     fprintf(student_file,"ID : %d   Name:%s\n",details[j].id,details[j].name);
                     printf("ID : %d   Name:%s\n",details[j].id,details[j].name);
                 }
            }
            fprintf(hsc_file,"\n\n");
            fprintf(student_file,"\n\n");
            printf("\n\n");
        }   
}

float  *delete_duplicate_element(float *array ,int option)  // a function that will delete the duplicate element and return the incoming array 
{
    int range= number_of_students;  //the loop will work till the number of students as it will be modified we are storing that in a different variable
    
    for(int i=0; i<range; i++)
    {
        for(int j=i+1; j<range; j++)
        {   
            if(array[i] == array[j])
            {
               
                for(int k=j; k < range - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                range--;  
                j--;
            }
        }
    }

    if (option == 1)  unique_total_gpa      = range;    //updating the value of the global variables
    else if (option == 2 ) unique_ssc_gpa   = range;
    else if (option == 3)  unique_hsc_gpa   = range;

    return array ;
    
}

float *sort_decreasing_order(float *array,int option)  //a function that will sort and return the array incoming in a descending order 
{
    int range;

    if (option == 1)         range = unique_total_gpa ;    //options for which kind of array is coming 
    else if (option == 2 )   range = unique_ssc_gpa   ;
    else if (option == 3)    range = unique_hsc_gpa   ;

    float swap;
        for (int i= 0 ; i< range - 1 ; i++)
            {
                for (int j = 0 ; j < range - i- 1; j++)
                    {
                    if (array[j] < array[j+1]) 
                        {
                            swap       = array[j];
                            array[j]   = array[j+1];      // using bubble sort to sort the array 
                            array[j+1] = swap;
                         }
                    }
            }
        return array;       
}

int main ()
{ 
    FILE *student_file = fopen ("student_data.txt", "r"); // opening the file in reading mode to scan the data's from the file 

    //checking if the pointer contains anything if it does scanning will be done 
    if (student_file == NULL){
        printf("File not found \n");
    } else {
        file_scanner (); // scaning the data's from the file 
        fclose(student_file);
    }
    file_data_printer();  // printing the data's from the file

    //deleting the duplicate elements of array and sorting them in descending order in order to use 
    total_gpa_array_modified = sort_decreasing_order(  (delete_duplicate_element(total_gpa_arr,1) ) ,1); 
    ssc_gpa_array_modified   = sort_decreasing_order(  (delete_duplicate_element(ssc_gpa_arr  ,2) ) ,2);
    hsc_gpa_array_modified   = sort_decreasing_order(  (delete_duplicate_element(hsc_gpa_arr  ,3) ) ,3);

    total_gpa_analyzer();    // writing the data of total gpa in the file and appending in the student file
    ssc_gpa_analyzer();     // writing the data of ssc gpa in the file and appending in the student file
    hsc_gpa_analyzer();    // writing the data of ssc gpa in the file and appending in the student file

return 0;
}
