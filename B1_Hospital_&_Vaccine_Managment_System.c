#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Username:b
// passoword:1

//username:ayush101
//password:abcd1234

// for other passwords and usernames refer to adm_log.csv


// THIS IS A HOSPITAL AND COVID VACCINE MANAGEMENT.
// USER IS REQUIRED TO LOGIN THROUGH SOME PRE-EXISITING LOGIN CREDENTIALS.
// IN CASE OF ANY DISPERANCY IN CREDENTIALS CONTACT ADMINISTRATOR.
// TO EXIT THE PROGRAM PRESS '0' AT THE END.
// PRESS ANY OTHER KEY TO CONTINUE USING THE PROGRAM.





int p_id_r[1000];  //1
char phone_r[1000][1000]; //6
int d_id_r[1000];  //10
int room_r[1000];  //8
int age_r[1000];  //3

char name_r[1000][1000];  //2
char sex_r[1000][1000];  //4
char add_r[1000][1000];  //5
char stat_r[1000][1000]; //7
char sym_r[1000][1000];  //9
char room_type_r[1000][1000];
char date_r[15][1000];

int ccount=0;    //This is to Count Number of Columns
int wcount=0;    //This is to Count Number of Characters
int rcount=0;    //This is to count Number of Rows

int a_count;
int ventcount;
int gencount;
int icucount;

int choice,choice2;
int id_pos=-1;     //Patient id or location in array

int d_id_dr[1000]; //1
int age_dr[1000];  //3
int cabin_dr[1000]; //9
int pexp_dr[1000];  //11

char phone_dr[1000][1000];  //7
char spec_dr[1000][1000];   //8
char time1_dr[1000][10][7];  //10a
char time2_dr[1000][1000][7];  //10
char name_dr[1000][1000];  //2
char sex_dr[1000][1000];   //4
char adh_dr[1000][1000];     //6

char *fields[13]={"P_ID","Name","Age","Gender","Address","Contact Number","Admit Status","Room No.","Room Type","Symptoms","D_ID","Date"};
char *fields_dr[13]={"D_ID","Name","Age","Gender","Contact Number","Aadhaar Number","Specialisation","Cabin Number","Experience"};
char *week_dr[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
char *fields_vc[13]={"Vac_Status","Vac_1_Date","Vac_2_date","Vac_Type","Aadhaar_Number","Name","Gender","Age","Phone"};
char *fields_vacc1[5]={"Date","Covaxine","Covishield","Sputnik","Registered"};

int status_vc[1000];
char aadhar_vc[1000][1000];
char phone_vc[1000][1000];
int age_vc[1000];

char date2_vc[1000][1000];
char entered_vc[1000][1000];
char  name_vc[1000][1000];
char gender_vc[10000][1000];
char vtype_vc[1000][1000];
char date_vc[1000][1000];

int att=0;

struct vac1{
    char date_r[1000];
    int covaxine_r;
    int covishield_r;
    int sputnik_r;
    int registered_r;
};



void firstscreen(){              //Function for first screen
    char k;
    printf("\n\t***********************");
    printf("\n\t      WELCOME TO");
    printf("\n\t     CITY HOSPITAL");
    printf("\n\t***********************\n");
    // printf("\nPress ENTER to continue");

    printf("====================================================\n");
    printf("Press 1 For Patient Records:-\n");
    printf("Press 2 For Doctor Records:-\n");
    printf("Press 3 For Bed Managment:-\n");
    printf("Press 4 For Covid-19 Vaccination Records:-\n");
    printf("Press 5 For Covid-19 Vaccine Stocks:-\n");


    //system("cls");
}







void title(){             //title function which will appear on every screen.
    printf("\n=======CITY HOSPITAL=======\n");
}







void p_rec(){           //This Block of code is to Take input for patient details

    char temp[1000];
    char temp1[1000];
    char temp2[1000];

    int p_id[1000];

    char phone[1000];
    int d_id[1000];
    int room[1000];
    int age[1000];

    char name[1000][1000];
    char sex[1000];
    char add[1000];
    char stat[1000];
    char sym[1000];
    char n[1000];
    char date[1000];
    int row=rcount;

    if(att==0){row=row-1;};         //this is to change the index of the Row count when file is found
    //elif(att==1){}

    printf ("\n<<<<<<<ADD PATIENT RECORD>>>>>>>>>>\n");
    
            //printf("%d\n",row);
            printf("Enter Date:");              //For date Input
            scanf("%s",&date);

            printf("Patient id:%d\n",p_id_r[row]+1);        //For Patient ID

            printf("Enter Name:");                //For Name Input
             scanf("%c",&temp);
            scanf("%[^\n]",&name);

            printf("Enter Age :");                  //For Age input
            scanf("%d",&age[0]);

            printf ("Enter gender(M/F/O):");            // For Gender Entry 
            scanf ("%s",&sex);

            printf ("Enter address:");                  //For Address Entry 
            scanf("%c",&temp1);
            scanf("%[^\n]",&add);

            printf ("Enter contact number:");           //Contact number
            scanf ("%s",&phone);

            printf ("Enter status (A.admitted/ N.not admitted)");       //Admitted
            scanf ("%s",&stat);
            if (stat[0]=='A'||stat[0]=='a'){
                printf ("Admitted\n");
                printf ("Enter room no:\n");
                scanf ("%d",&room[0]);

                printf ("\n  PRESS'G'IF GENERAL WARD || PRESS'I'IF ICU || PRESS'V'IF  VENTILATOR\n");  
                printf("Input>>>>>");
                scanf ("%s",&n);


                if (n[0]=='G'||n[0]=='g'){
                    printf ("PATIENT IS ADMITTED TO GENERAL WARD\n");           //for general ward
                    //gencount=gencount+1;
                    //printf ("%d",gencount);
                }
                else if (n[0]=='I'||n[0]=='i'){
                    printf ("PATIENT IS ADMITTED TO ICU WARD\n");               //For ICU Ward
                    //icucount++;
                }
                else if (n[0]=='V'||n[0]=='v'){
                    printf ("PATIENT IS ON LIFE SUPPORT\n");                    //Ventilator
                   // ventcount++;
                }


            }
            else if (stat[0]=='N'||stat[0]=='n'){
                    printf ("\nNot Admitted\n");
            }



            printf ("Enter symptoms:");                                         //Symtomps
            scanf("%c",&temp2);
            scanf ("%[^\n]",&sym);


            printf ("Enter doctor I.d:");                                       //Doctor ID
            scanf ("%d",&d_id[0]);




    system("cls");
    printf ("\n<<<<patient record added>>>>\n");



    FILE *ptr;
    ptr=fopen("p_rec.csv","a+");                                          //For Appending New patient Data Into the file
    fprintf(ptr,"%d,%s,%d,%s,%s,%s,%s,%d,%s,%s,%d,%s\n",p_id_r[row]+1,name,age[0],sex,add,phone,stat,room[0],n,sym,d_id[0],date);
    fclose(ptr);
    
    strcpy(n,"");
    room[0]=0;

}






void readfile(){            //this block is to read file and display data  the pateint id
    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    int r,ro,x,y;
    r=ro=x=y=0;


    


    FILE *ptr;                               //This Block of code is to Count Number of Columns
    ptr=fopen("p_rec.csv","r");

    if(ptr!=NULL){                          //If the file is found this block will run Other wise Else will run

    for(int i=0;z!='\n';i++){
        fscanf(ptr,"%c",&z);
        //printf("%c",z);
        if(z==','){
            ccount=ccount+1;
        }
        else if(z==EOF){
            break;
        }
    }
    ccount=ccount+1;                        //to make count the number of fields
    fclose(ptr);




    FILE *ptr2;                          //This block of code is to Count Number of Rows and Characters in the file
    ptr2=fopen("p_rec.csv","r");
    for(int i=0;c!=EOF;i++){
    c=fgetc(ptr);

    //printf("%c",c);
    
    if(c!='\n'){
        wcount=wcount+1;
    }
        else if(c==EOF){
            printf("EOF found\n");
        }
        else{
            rcount=rcount+1;
        }



    }
    wcount=wcount+1;

    //printf("\nRow Count:%d\n",rcount);

    fclose(ptr);




    FILE *ptr1;                                            //THis Block of code is to Read character by character from file and put it into Arrays
    
    ptr1=fopen("p_rec.csv","r");                           //According to their respective data type
    
    //printf("Character Count:%d\n",wcount);
    
    for(int i=0;c1!=EOF;i++){                               //Here this loop is made to Run till EOF(End of file)
        c1=fgetc(ptr1);
        //printf("%c",c1);
        if((c1==',' || c1=='\n')|| (c1==EOF) ){           //Here we separate the insertion process by these three conditions
            //printf("%s ",str);
            if(r==0){                                       //Patient ID
                p_id_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==1){                                  //Name Combined
                strcpy(name_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==2){                                  //Age
                age_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }
            else if(r==3){                                  //Gender
                strcpy(sex_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==4){                                  //Address
                strcpy(add_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==5){                                  //Contact Number
                strcpy(phone_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==6){                                  //Admitted Status
                strcpy(stat_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==7){                                  //Symptoms
                room_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }
            else if(r==8){                                  //symptoms
                strcpy(room_type_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==9){                                  //symptoms
                strcpy(sym_r[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==10){                                  //Doctor ID
                d_id_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }
            else if(r==11){                                  //Date Admitted
                strcpy(date_r[ro],str);
                strcpy(str,"");

                ro=ro+1;
                r=0;
            }


    }
    else{
            strncat(str,&c1,1);//it will append the characters                      //This the part where we concatenate the characters to make it insertable String
        }
    }
    printf("\n");
    fclose(ptr1);
    }

    else{                       //this will run when the Doctor record file will not be found 
        p_id_r[0]=0;
        att=1;
    }
}







void idsearch(){                    //This Block is to search the patient record from the data and put it through other functions.
    int pat_id;

    printf("Enter Patient ID:");            //Input the Patient ID for Searching in the Record
    scanf("%d",&pat_id);

    for (int i=0;i<rcount+1;i++){
        printf("%d",p_id_r[i]);
        if(pat_id==p_id_r[i]){                  //When the patient id will be found in the file loop will be terminated
            id_pos=i;
            break;
        }
    }

    if(id_pos!=-1){                         // This will run when the record will be found in the above and editing part will be executed
        if(choice2==3){
            filedit();                         //This is to edit the patient record which is called when we input 3 in the main executer itself
            p_write();
        }
    }


    if(id_pos!=-1){                     //This block is to Display all the Data after editing or Searching

        printf("%s: %d \n",fields[0],p_id_r[id_pos]);
        printf("%s: %s \n",fields[1],name_r[id_pos]);
        printf("%s: %d \n",fields[2],age_r[id_pos]);
        printf("%s: %s \n",fields[3],sex_r[id_pos]);
        printf("%s: %s \n",fields[4],add_r[id_pos]);
        printf("%s: %s \n",fields[5],phone_r[id_pos]);
        printf("%s: %s \n",fields[6],stat_r[id_pos]);
        printf("%s: %d \n",fields[7],room_r[id_pos]);
        printf("%s: %s \n",fields[8],room_type_r[id_pos]);
        printf("%s: %s \n",fields[9],sym_r[id_pos]);
        printf("%s: %d \n",fields[10],d_id_r[id_pos]);
        printf("%s: %s \n",fields[11],date_r[id_pos]);
        printf("====================================================\n");

    }
    else{
        printf("<<<<No Match Found!>>>>");                  //When the data will not be found value of id_pos will not be changed
    }
}







void filedit(){             //This block is to Edit data in the retrived data arrays which are formed with readfile fxn
    char temp1;

    for(int i=1;i<12;i++){
        printf("Press %d for %s:-\n",i,fields[i]);
    }
    printf("====================================================\n");

    int choice3;
    printf("Input>>>>");
    scanf("%d",&choice3);

    //choice3=choice3-1;

    // if(choice3==0){
    //     printf("Enter New %s:",fields[choice3]);
    //     scanf("%d",&p_id_r[id_pos]);
    // }
    if(choice3==1){
        printf("Enter New %s:",fields[choice3]);
        scanf("%c",&temp1);
        scanf("%[^\n]",&name_r[id_pos]);
    }
    else if(choice3==2){
        printf("Enter New %s:",fields[choice3]);
        scanf("%d",&age_r[id_pos]);
    }
    else if(choice3==3){
        printf("Enter New %s:",fields[choice3]);
        scanf("%s",&sex_r[id_pos]);
    }
    else if(choice3==4){
        printf("Enter New %s:",fields[choice3]);
        scanf("%c",&temp1);
        scanf("%[^\n]",&add_r[id_pos]);
    }
    else if(choice3==5){
        printf("Enter New %s:",fields[choice3]);
        scanf("%s",&phone_r[id_pos]);
    }
    else if(choice3==6){
        printf("Enter New %s:",fields[choice3]);
        scanf("%s",&stat_r[id_pos]);

        if (strcmp(stat_r[id_pos],"N")==0 || strcmp(stat_r[id_pos],"n")==0 ){
            room_r[id_pos]=0;
            strcpy(room_type_r[id_pos],"");
        }

        else if(strcmp(stat_r[id_pos],"A")==0 || strcmp(stat_r[id_pos],"a")==0 ){
            printf("Enter New %s:",fields[7]);
            scanf("%d",&room_r[id_pos]);

            printf("Enter New %s:",fields[8]);
            scanf("%s",&room_type_r[id_pos]);
        }
    }
    else if(choice3==7){
        printf("Enter New %s:",fields[choice3]);
        scanf("%d",&room_r[id_pos]);
    }
    else if(choice3==8){
        printf("Enter New %s:",fields[choice3]);
        scanf("%s",&room_type_r[id_pos]);
    }
    else if(choice3==9){
        printf("Enter New %s:",fields[choice3]);
        scanf("%c",&temp1);
        scanf("%[^\n]",&sym_r[id_pos]);
    }
    else if(choice3==10){
        printf("Enter New %s:",fields[choice3]);
        scanf("%d",&d_id_r[id_pos]);
    }
    else if(choice3==11){
        printf("Enter New %s:",fields[choice3]);
        scanf("%s",&date_r[id_pos]);
    }
}







void p_write(){                     //This Block takes all the changed data and write it in the main csv file.
    //printf("Okay 1");

    FILE *ptr;
    ptr=fopen("p_rec.csv","w");

    //printf("Okay 2");

    for(int i=0;i<rcount;i++){
        fprintf(ptr,"%d,%s,%d,%s,%s,%s,%s,%d,%s,%s,%d,%s\n",
        p_id_r[i],name_r[i],age_r[i],sex_r[i],add_r[i],phone_r[i],stat_r[i],room_r[i],room_type_r[i],sym_r[i],d_id_r[i],date_r[i]);
    }
    fclose(ptr);
    printf("\n<<<<Data EDITED>>>>\n");
}







void d_rec(){
    
    int d_id[1000]; //1

    //d_id_dr[0]=0;

    int age[1000];    //3
    int cabin[1000];
    int pexp[1000];

    char phone[1000];
    char spec[1000];
    char time1[1000][8];
    char time2[1000][8];
    char name[1000][1000];  //2
    char sex[1000];
    char adh[1000];
    char temp1[1000];
    char temp2[1000];
    int m,n,z=0;
    int row=rcount;
    
    printf("%d\n",row);
    printf("%d\n",att);
    if (att==0){
         row=row-1;
         
    }


    printf("\n<<<<<<<<ADD DOCTOR RECORD>>>>>>>>\n");

    printf("Enter Doctor ID:%d\n",d_id_dr[row]+1);
    //printf("%d",rcount);

    printf("Enter First Name:");                    //First Name    
    scanf("%s",&name[0]);
    printf("Enter Last Name:");                     //Last Name
    scanf("%s",&name[1]);

    printf("Enter Age :");                          //Age
    scanf("%d",&age[0]);

    printf("Enter Aadhaar Number:");                 //Aadhar Number
    scanf("%s",&adh);
    printf ("Enter gender(M/F/O):");                 //Gender
    scanf ("%s",&sex);

    printf ("Enter contact number:");                //Contact Number
    scanf ("%s",&phone);

    printf ("Enter specialization:");                //Specilization
    scanf("%c",&temp2);
    scanf ("%[^\n]",&spec);

    printf("Enter cabin no.:");                      //Cabin Number
    scanf("%d",&cabin[0]);

    printf("Timing details\n");                      //Time From: To:
    for(m=0;m<7;m++){
        printf("Timings for day %d of the week:",m);
        printf("\nfrom:");
        scanf("%s",&time1[m]);
        printf("To:");
        scanf("%s",&time2[m]);
        printf("==========================\n");
    }
    
    printf("Enter Experience Years:");              //Experience Years
    scanf ("%d",&pexp[0]);

    //system("cls");


    FILE *ptr;
    ptr=fopen("drec.csv","a+");                 // this is to append the data of New doctors Appointed by the Hospital
    //printf("%d,%s %s,%d,%s,%s,%s,%s,%d",d_id[0],name[0],name[1],age[0],sex,phone,adh,spec,cabin[0]);
    fprintf(ptr,"%d,%s %s,%d,%s,%s,%s,%s,%d",d_id_r[row]+1,name[0],name[1],age[0],sex,phone,adh,spec,cabin[0]);

    for(int i=0;i<7;i++){
        fprintf(ptr,",%s,%s",time1[i],time2[i]);        //This is for time from: to to:
        //printf(",%s,%s",time1[i],time2[i]);
    }

    fprintf(ptr,",%d\n",pexp[0]);           //this is for doctor Experience
    fclose(ptr);
    printf("\n<<<<<Doctor Record Added>>>>");

 }




void d_read(){            //this block is to read file and display dataof doctor records by the doctor ID
    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    int r,ro,x,y;
    r=ro=x=y=0;
    int z1=0;
    




    FILE *ptr;                               //This Block of code is to Count Number of Columns
    ptr=fopen("drec.csv","r");
    if (ptr!=NULL){

    for(int i=0;z!='\n';i++){
        fscanf(ptr,"%c",&z);
        //printf("%c",z);
        if(z==','){
            ccount=ccount+1;
        }
        else if(z==EOF){
            break;
        }
    }
    ccount=ccount+1;//to make count the number of fields
    //printf("fields:%d\n",ccount);
    fclose(ptr);
    //printf("2");


    // printf("asas");

    FILE *ptr2;                          //This block of code is to Count Number of Rows and Characters in the file
    ptr2=fopen("drec.csv","r");
    for(int i=0;c!=EOF;i++){
    c=fgetc(ptr);
    //printf("%c",c);
    if(c!='\n'){
        wcount=wcount+1;
    }
        else if(c==EOF){
            printf("EOF found\n");
        }
        else{
            rcount=rcount+1;
        }



    }
    wcount=wcount+1;
    printf("\nRow Count:%d\n",rcount);

    fclose(ptr);




    FILE *ptr1;                                            //This Block of code is to Read charcter by chracter from file and put it into Arrays
    ptr1=fopen("drec.csv","r");                           //According to their respective data type
    //printf("1\n");

    printf("Character Count:%d\n",wcount);
    for(int i=0;c1!=EOF;i++){                               //Here this loop is made to Run till EOF(End of file)
        c1=fgetc(ptr1);
        //printf("%c",c1);
        if((c1==',' || c1=='\n')|| (c1==EOF) ){           //Here we seprate the insertion process by these three conditions
            //printf("%s ",str);
            if(r==0){                                       //Doctor ID
                //printf("%s ",str);
                d_id_dr[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==1){                                  //Name Combined
                strcpy(name_dr[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==2){                                  //Age
                age_dr[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }
            else if(r==3){                                  //Gender
                strcpy(sex_dr[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==4){                                  //Phone
                strcpy(phone_dr[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==5){                                  //Adhar Number
                strcpy(adh_dr[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==6){                                  //Specialisation
                strcpy(spec_dr[ro],str);
                strcpy(str,"");
                r++;
            }
            else if(r==7){                                  //cabin number
                cabin_dr[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }
            else if(r==8){                                  //Time from
                //printf("%d\n",z1);
                //time1_dr[ro][z1]=atoi(str);
                strcpy(time1_dr[ro][z1],str);
                strcpy(str,"");
                r++;
            }
            else if(r==9){                                  //Time To
                //time2_dr[ro][z1]=atoi(str);
                strcpy(time2_dr[ro][z1],str);
                strcpy(str,"");

                if(z1==6){
                    r=10;
                    z1=-1;
                    // printf("%d\n",z1);
                }

                else{r=8;}

                z1++;
            }
            else if(r==10){                                  //Doctor Experience years
                // printf("\n %d\n",z1);
                pexp_dr[ro]=atoi(str);
                strcpy(str,"");
                
                r=0;
                ro=ro+1;
            }


    }
    else{
            strncat(str,&c1,1);//it will append the characters                      //This the part where we concartenate the characters to make it insertable String
        }
    }
    //printf("Hello");
    //for(int i=0;i<5;i++){
    //    printf("%s: %d \n",fields_dr[0],d_id_dr[i]);
    //}
    }
    else{               //This will run when the file will not be found by the pointer
        d_id_dr[0]=0;
        att=1;
        //printf("a");
    }
}







void d_display(){                   //This block of code is Display Data of Doctor Followed by their Doctor ID

    printf("Enter Doctor ID:");
    int d_id;
    scanf("%d",&d_id);
    printf("====================================================\n");
    int id_pos=-1;
    for (int i=0;i<rcount+1;i++){
        //printf("%d",d_id_dr[i]);
        if(d_id==d_id_dr[i]){               //This is the block for searching Doctor ID...
            id_pos=i;
            
            break;
        }
    }

    
    if(id_pos!=-1){     
        printf("%s: %d \n",fields_dr[0],d_id_dr[id_pos]);
        printf("%s: %s \n",fields_dr[1],name_dr[id_pos]);
        printf("%s: %d \n",fields_dr[2],age_dr[id_pos]);
        printf("%s: %s \n",fields_dr[3],sex_dr[id_pos]);
        printf("%s: %s \n",fields_dr[4],phone_dr[id_pos]);                                                                    
        printf("%s: %s \n",fields_dr[5],adh_dr[id_pos]);
        printf("%s: %s \n",fields_dr[6],spec_dr[id_pos]);
        printf("%s: %d \n",fields_dr[7],cabin_dr[id_pos]);
        printf("%s: %d \n",fields_dr[8],pexp_dr[id_pos]);
        printf("====================================================\n");
        for(int i=0;i<7;i++){
            printf("%s>>> [From:%s  To:%s]\n",week_dr[i],time1_dr[id_pos][i],time2_dr[id_pos][i]);
        }

    }
    else{
        printf("<<<<No Match Found!>>>>");
    }

}




void d_filedit(){             //This block takes the data from the user and change it into Retrived Data arrays.
    char temp1;

    printf("Enter Doctor ID:");
    int d_id;
    scanf("%d",&d_id);
    printf("====================================================\n");
    for (int i=0;i<rcount+1;i++){
        //printf("%d",d_id_dr[i]);
        if(d_id==d_id_dr[i]){       //For searching Doctor ID
            id_pos=i;
            
            break;
        }


    }
    if(id_pos!=-1){
        for(int i=1;i<9;i++){
            printf("Press %d for %s:-\n",i,fields_dr[i]);               //For menu
        }
        printf("Press 9 for Timings:-\n");
        printf("====================================================\n");

        int choice3;
        printf("Input>>>>");                    //Choice of above menu
        scanf("%d",&choice3);
        
        //choice3=choice3-1;
        // if(choice3==0){
        //     printf("Enter New %s:",fields_dr[choice3]);
        //     scanf("%d",&d_id_dr[id_pos]);
        // }
        if(choice3==1){                                     //Name
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%c",&temp1);
            scanf("%[^\n]",&name_dr[id_pos]);
        }
        else if(choice3==2){
            printf("Enter New %s:",fields_dr[choice3]);         //Age 
            scanf("%d",&age_dr[id_pos]);
        }
        else if(choice3==3){            //gender
            printf("Enter New %s:",fields_dr[choice3]);
            scanf(" %c",&sex_dr[id_pos]);
        }
        else if(choice3==4){                                    //Phone
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%s",&phone_dr[id_pos]);
        }
        else if(choice3==5){                                    //Adhar
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%s",&adh_dr[id_pos]);
        }
        else if(choice3==6){                                    //Specialisation
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%s",&spec_dr[id_pos]);
        }
        else if(choice3==7){                                        //Cabin number
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%d",&cabin_dr[id_pos]);
        }
        else if(choice3==8){                                          //Doctor Experience
            printf("Enter New %s:",fields_dr[choice3]);
            scanf("%d",&pexp_dr[id_pos]);
        }
        else if(choice3==9){
                                                                //Timeings
            printf("====================================================\n");
            int i;
            for(i=0;i<7;i++){
                printf("For %s Press %d\n",week_dr[i],i);
            }
            printf("====================================================\n");
            printf("Input>>>>");
            scanf("%d",&i);

            printf("From:");
            scanf("%s",&time1_dr[id_pos][i]);

            printf("To:");
            scanf("%s",&time2_dr[id_pos][i]);
        }


                                                                                //Display Data

        printf("%s: %d \n",fields_dr[0],d_id_dr[id_pos]);
        printf("%s: %s \n",fields_dr[1],name_dr[id_pos]);
        printf("%s: %d \n",fields_dr[2],age_dr[id_pos]);
        printf("%s: %s \n",fields_dr[3],sex_dr[id_pos]);
        printf("%s: %s \n",fields_dr[4],phone_dr[id_pos]);                                                                    
        printf("%s: %s \n",fields_dr[5],adh_dr[id_pos]);
        printf("%s: %s \n",fields_dr[6],spec_dr[id_pos]);
        printf("%s: %d \n",fields_dr[7],cabin_dr[id_pos]);
        printf("%s: %d \n",fields_dr[8],pexp_dr[id_pos]);
        printf("====================================================\n");


        for(int i=0;i<7;i++){
            printf("%s>>> [From:%s  To:%s]\n",week_dr[i],time1_dr[id_pos][i],time2_dr[id_pos][i]);
        }
    }

    else{
        printf("<<<<No Match Found!>>>>\n");
    }
}



void d_write(){         //This Block takes all the changed data and write it in the main csv file.
    printf("yes");
    FILE *ptr;
    ptr=fopen("drec.csv","w");
    //printf("yes");
    printf("%d\n",rcount);
    for(int i=0;i<rcount;i++){
        fprintf(ptr,"%d,%s,%d,%s,%s,%s,%s,%d",d_id_dr[i],name_dr[i],age_dr[i],sex_dr[i],phone_dr[i],adh_dr[i],spec_dr[i],cabin_dr[i]);
        
        for(int j=0;j<7;j++){
        fprintf(ptr,",%s,%s",time1_dr[i][j],time2_dr[i][j]);
        }

        fprintf(ptr,",%d\n",pexp_dr[i]);

    }
    fclose(ptr);
    printf("\n<<<<Data EDITED>>>>\n");

    
}





int adm_login(){                                        //This is to set login for a admin based account
    struct log1{
        char na_ps[100][2][1000];      //user name and password 3D array from the file
        char user_p[1][100];           //user name and password as inputed by the user
        
    };

    char cc[1000];
    char cc1[1000];

    struct log1 log;
    printf("Enter Username:");
    scanf("%s",&cc);
    strcpy(log.user_p[0],cc);

    printf("\n");

    printf("Enter Password:");
    scanf("%s",&cc1);
    system("cls");
    strcpy(log.user_p[1],cc1);



    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    int r,ro,x,y;
    r=ro=x=y=0;
    




    FILE *ptr;                               //This Block of code is to Count Number of Columns
    ptr=fopen("adm_log.csv","r");
    for(int i=0;z!='\n';i++){
        fscanf(ptr,"%c",&z);

        if(z==','){
            ccount=ccount+1;
        }
        else if(z==EOF){
            break;
        }
    }
    ccount=ccount+1;//to make count the number of fields

    fclose(ptr);



    FILE *ptr2;                          //This block of code is to Count Number of Rows and Characters in the file
    ptr2=fopen("adm_log.csv","r");
    for(int i=0;c!=EOF;i++){
    c=fgetc(ptr);
    
    if(c!='\n'){
        wcount=wcount+1;
    }
        else if(c==EOF){
            printf("EOF found\n");
        }
        else{
            rcount=rcount+1;
        }



    }
    wcount=wcount+1;
    

    fclose(ptr);




    FILE *ptr1;                                            //THis Block of code is to Read charcter by caracter from file and put it into Arrays
    ptr1=fopen("adm_log.csv","r");                           //According to their respective data type
    


    
    for(int i=0;c1!=EOF;i++){                               //Here this loop is made to Run till EOF(End of file)
        c1=fgetc(ptr1);
        
        if((c1==',' || c1=='\n')|| (c1==EOF) ){           //Here we seprate the insertion process by these three conditions
            
            if(r==0){                                       //Username to Array
                
                strcpy(log.na_ps[ro][0],str);
                strcpy(str,"");
                r++;
            }

            else if(r==1){                                  //Password to array
                strcpy(log.na_ps[ro][1],str);
                strcpy(str,"");

                r=0;
                ro=ro+1;
            }


    }
    else{
            strncat(str,&c1,1);//it will append the characters                      //This the part where we concartenate the characters to make it insertable String
        }
    }
    printf("\n");
    fclose(ptr1);//closing file                                                      //This is just to print the data we obtained in the Arrays A1 A2 A3
    
    
    
    int res=0;
    int res1=0;
    int res2=1;
    for (int i=0;i<rcount;i++){

        res=strcmp(log.user_p[0],log.na_ps[i][0]);
        res1=strcmp(log.user_p[1],log.na_ps[i][1]);
        if (res==0 && res1==0){
            res2=0;
            break;
        }
    }
    
    ccount=0;    
    wcount=0;    
    rcount=0;

    return res2;
}






void add_ben(){                                     //This is to add vaccine benifitiary record to the files
    int reg=0;
    char phone[1000];
    char name[1000];
    char sex[1000];
    char add[1000];
    char stat[1000];
    char sym[1000];
    char temp1[1000];
    char temp2[1000];
    char temp3[1000];
    int status[1000];
    char aadhar[1000];
    char dose1[1000], dose2[1000];
    int age[1000];
    char vacc_type[100];

    char temp;


    printf("Press 1 For Partially vaccinated:-\n");
    printf("Press 2 For Fully Vaccinated:-\n");
    scanf ("%d",&status[0]);
        if (status[0]==1){
            printf("Date of dose-1:");
            scanf("%s", &dose1);

            printf("Estimated date of dose 2:");
            scanf("%s", &dose2);
            }
        else if (status[0]==2){
            printf("Date of dose-1:");
            scanf("%s", &dose1);

            printf("Date of dose 2:");
            scanf("%s", &dose2);
            }

    printf("Enter vaccine type:");
    scanf ("%s",&vacc_type);

    printf("Enter Aadhar number:");
    scanf("%s", &aadhar );

    printf("Enter the name:");
    scanf("%c",&temp);
    scanf ("%[^\n]",&name);

    printf("Enter the gender:");
    scanf("%s",&sex);

    printf("Enter the age:");
    scanf("%d", &age[0]);

    printf("Enter the phone number:");
    scanf("%s", &phone );



    FILE*fptr;
    fptr = fopen("bendata.csv", "a+");
    fprintf (fptr,"%d,%s,%s,%s,%s,%s,%s,%d,%s\n",status[0],dose1,dose2,vacc_type,aadhar,name,sex,age[0],phone);


    fclose(fptr);
    printf("<<<Record Added>>>");

}





void readfile_vc(){                                     //this is to read vaccine data from the file 
    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    int r=0;
    int ro=0;
    int x=0;
    int y=0;


    //printf("Enter the date");
    //scanf("%s",&entered_vc);
    FILE *ptr;                                      
        ptr=fopen("bendata.csv","r");
        for(int i=0;z!='\n';i++){
            fscanf(ptr,"%c",&z);
            //printf("%c",z);
            if(z==','){
                ccount=ccount+1;
            }
            else if(z==EOF){
                break;
            }
        }
        ccount=ccount+1;

        fclose(ptr);




        FILE *ptr2;
        ptr2=fopen("bendata.csv","r");
        for(int i=0;c!=EOF;i++){
        c=fgetc(ptr);
        //printf("%c",c);
        if(c!='\n'){
            wcount=wcount+1;
        }
            else if(c==EOF){
                printf("EOF found\n");
            }
            else{
                rcount=rcount+1;
            }
        }
        wcount=wcount+1;
        fclose(ptr);



        FILE *ptr1;
        ptr1=fopen("bendata.csv","r");
        for(int i=0;c1!=EOF;i++){
            c1=fgetc(ptr1);
            //printf("%s",str);
            //printf("%c",c1);

            if((c1==',' || c1=='\n')|| (c1==EOF) ){


                if(r==0){

                    status_vc[ro]=atoi(str);
                    strcpy(str,"");
                    r++;
                    //printf("@1");
                }
                else if(r==1){
                    strcpy(date_vc[ro],str);    //date of dose1
                    strcpy(str,"");
                    r++;
                }
                else if(r==2){               //date of dose 2
                    strcpy(date2_vc[ro],str);
                    strcpy(str,"");
                    r++;
                }

                else if(r==3){
                    strcpy(vtype_vc[ro],str);//vaccine type
                    strcpy(str,"");
                    r++;
                }

                else if(r==4){//Adhar number
                    strcpy(aadhar_vc[ro],str);
                    strcpy(str,"");
                    r++;
                }
                else if(r==5){//Name
                    strcpy(name_vc[ro],str);
                    strcpy(str,"");
                    r++;
                }
                else if(r==6){//gender
                    strcpy(gender_vc[ro],str);
                    strcpy(str,"");
                    r++;
                }
                else if(r==7){//age
                    age_vc[ro]=atoi(str);
                    strcpy(str,"");
                    r++;
                }
                else if(r==8){//phone
                    strcpy(phone_vc[ro],str);
                    strcpy(str,"");
                    r=0;
                    ro=ro+1;
                }
            }
        else{
                strncat(str,&c1,1);
            }
        }

    

    // for(int i=0;i<rcount;i++){
    //     printf("%s: %d \n",fields_vc[0],status_vc[i]);
    //     printf("%s: %s \n",fields_vc[1],date_vc[i]);
    //     printf("%s: %s \n",fields_vc[2],date2_vc[i]);
    //     printf("%s: %s \n",fields_vc[3],vtype_vc[i]);
    //     printf("%s: %d \n",fields_vc[4],aadhar_vc[i]);                                                                    
    //     printf("%s: %s \n",fields_vc[5],name_vc[i]);
    //     printf("%s: %s \n",fields_vc[6],gender_vc[i]);
    //     printf("%s: %d \n",fields_vc[7],age_vc[i]);
    //     printf("%s: %d \n",fields_vc[8],phone_vc[i]);
    // }
    
    printf("====================================================\n");


    // if(entered_vc==date_vc){               //fOR checking the no. of registration done on particular date.
    //    printf("\n%d",reg);
    // }
  
    fclose(ptr1);
}




void filedit_vc(){             //This block is to edit vaccine data by the user followed by their User ID
    char temp1;

    for(int i=0;i<9;i++){
        printf("Press %d for %s:-\n",i,fields_vc[i]);
    }

    printf("====================================================\n");

    int choice3;
    printf("Input>>>>");
    scanf("%d",&choice3);
    
    //choice3=choice3-1;
    if(choice3==0){                     //status vaccine
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%d",&status_vc[id_pos]);
    }
    else if(choice3==1){// date 1
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",&date_vc[id_pos]);
    }
    else if(choice3==2){//date 2
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",&date2_vc[id_pos]);
    }
    else if(choice3==3){//vaccine type
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",&vtype_vc[id_pos]);
    }
    else if(choice3==4){//Aadhar 
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",aadhar_vc);
    }
    else if(choice3==5){//name 
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%c",&temp1);
        scanf("%[^\n]",&name_vc[id_pos]);
    }
    else if(choice3==6){//gender
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",&gender_vc[id_pos]);
    }
    else if(choice3==7){//age
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%d",age_vc[id_pos]);
    }
    else if(choice3==8){//phone 
        printf("Enter New %s:",fields_vc[choice3]);
        scanf("%s",phone_vc[id_pos]);
    }
}





void idsearch_vc(){            //This Block is to search the patient record from the data and put it through other functions.
    char adh_id[100];
    printf("Enter Aadhar ID:");
    scanf("%s",&adh_id);
    for (int i=0;i<rcount+1;i++){  //searching by adhar chard id
        if(0==strcmp(adh_id,aadhar_vc[i]) ){
            id_pos=i;
            break;
        }
    }

    if(id_pos!=-1){
        if(choice2==3){
            filedit_vc();       //when edit will be choosen this will run
            vc_write();
        }
    }

    
    if(id_pos!=-1){                         //for printing data
        printf("%s: %d \n",fields_vc[0],status_vc[id_pos]);
        printf("%s: %s \n",fields_vc[1],date_vc[id_pos]);
        printf("%s: %s \n",fields_vc[2],date2_vc[id_pos]);
        printf("%s: %s \n",fields_vc[3],vtype_vc[id_pos]);
        printf("%s: %s \n",fields_vc[4],aadhar_vc[id_pos]);                                                                    
        printf("%s: %s \n",fields_vc[5],name_vc[id_pos]);
        printf("%s: %s \n",fields_vc[6],gender_vc[id_pos]);
        printf("%s: %d \n",fields_vc[7],age_vc[id_pos]);
        printf("%s: %s \n",fields_vc[8],phone_vc[id_pos]);
        printf("====================================================\n");

    }
    else{
        printf("<<<<No Match Found!>>>>");
    }
}





void vc_write(){         //This Block takes all the changed data and write it in the main csv file.
    FILE *ptr;
    ptr=fopen("bendata.csv","w");
    char adh[100];
    char phn[100];
    for(int i=0;i<rcount;i++){
        fprintf (ptr,"%d,%s,%s,%s,%s,%s,%s,%d,%s\n",status_vc[i],date_vc[i],date2_vc[i],vtype_vc[i],aadhar_vc[i],name_vc[i],gender_vc[i],age_vc[i],phone_vc[i]);
    }
    fclose(ptr);
    printf("\n<<<<Data EDITED>>>>\n");
}




void bed(){ // this function reads the patient data and calculate total beds and available beds of different category
    int a_count=0;
    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    char choice1,choice2;
    int r,ro,x,y;
    r=ro=x=y=0;
    int i,n;
    int total,gen,vent,icu,a_gen,a_vent,a_icu;

    printf ("<<<<<<<<<BED MANAGEMENT SYSTEM>>>>>>>\n");


    total=1100;
    gen=700;
    vent=150;
    icu=250;

    printf ("Total Beds:%d\n",total);
    printf ("Total Beds in General Ward:%d\n",gen);
    printf ("Total Beds in ICU:%d\n",icu);
    printf ("Total Ventilators:%d\n",vent);



     FILE *ptr;                                //this block reads columns of csv file
    ptr=fopen("p_rec.csv","r");
    for(int i=0;z!='\n';i++){
        fscanf(ptr,"%c",&z);

        if(z==','){
            ccount=ccount+1;
        }
        else if(z==EOF){
            break;
        }
    }
    ccount=ccount+1;

    fclose(ptr);





    FILE *ptr2;                               //this block reads totals rows and words in csv file
    ptr2=fopen("p_rec.csv","r");
    for(int i=0;c!=EOF;i++){
    c=fgetc(ptr);
    //printf("%c",c);
    if(c!='\n'){
        wcount=wcount+1;
    }
        else if(c==EOF){
            //printf("EOF found\n");
        }
        else{
            rcount=rcount+1;
        }



    }
    wcount=wcount+1;


    fclose(ptr);




    FILE *ptr1;
    ptr1=fopen("p_rec.csv","r");
    for(int i=0;c1!=EOF;i++){
        c1=fgetc(ptr1);

        if((c1==',' || c1=='\n')|| (c1==EOF) ){


            if(r==0){

                p_id_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==1){
                strcpy(name_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==2){

                age_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==3){
                strcpy(sex_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==4){
                strcpy(add_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==5){
                strcpy(phone_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==6){
                strcpy(stat_r[ro],str);
                strcpy(str,"");
                //printf ("%s\n",stat_r[ro]);
                if(strcmp(stat_r[ro],"A")==0||strcmp(stat_r[ro],"a")==0){                       //it will check the admit status of patient
                  a_count++;                                                                    //this part will count total number of admitted patients
                    }
                r++;
            }

            else if(r==7){
                room_r[ro]=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==8){                                  //it will check room type of patient
                strcpy(room_type_r[ro],str);
                strcpy(str,"");
                if(strcmp(room_type_r[ro],"G")==0||strcmp(room_type_r[ro],"g")==0){         //This is the part where we count general beds currently occupied
                  gencount++;
                    }
                else if(strcmp(room_type_r[ro],"I")==0||strcmp(room_type_r[ro],"i")==0){    //here we count ICU beds currently occupied
                  icucount++;
                    }
                else if(strcmp(room_type_r[ro],"V")==0||strcmp(room_type_r[ro],"v")==0){    //Here we count Ventilators currently occupied
                  ventcount++;
                    }
                r++;
            }

            else if(r==9){
                strcpy(sym_r[ro],str);
                strcpy(str,"");
                r++;
            }

            else if(r==10){
                d_id_r[ro]=atoi(str);
                strcpy(str,"");

                r++;
            }

            else if(r==11){
                strcpy(date_r[ro],str);
                strcpy(str,"");

                r=0;
                ro=ro+1;
            }


    }
    else{
            strncat(str,&c1,1);
        }
    }


    printf("\n");
    fclose(ptr1);


    printf("Beds Available:%d\n",total-a_count);
    printf("Beds Available in General Ward:%d\n",gen-gencount);
    printf("ICU Beds Available:%d\n",icu-icucount);
    printf("Ventilators Available:%d\n",vent-ventcount);
    //display of fare details
    printf ("Press ('Y') To Get Fare Details:-\nPress ('N') To EXIT:-\n");
    printf("Input>>>>");
    scanf (" %c",&choice1);
    system ("cls");
    if (choice1=='Y'||choice1=='y'){
        printf("Press ('G') To Check Fare Of General Bed:-\nPress ('I') To Check Fare Of ICU Bed:-\nPress ('V') To Check Fare Of Ventilator:-\n");
        printf("Input>>>>");
        scanf(" %c",&choice2);

        if (choice2=='G'||choice2=='g'){
            system ("cls");
            printf ("Fare For General Bed: INR1000/Day\n[NOTE-Prices Of OXYGEN,MEDECINES,TESTS NOT INCLUDED]\n<<Prices Are GST EXCLUSIVE>>\n");
        }

        else if (choice2=='I'||choice2=='i'){
            system ("cls");
            printf ("Fare For ICU Bed: INR6400/DAY\n[NOTE-Prices Of OXYGEN,MEDECINES,TESTS NOT INCLUDED]\n<<Prices Are GST EXCLUSIVE>>\n");
        }

        else if (choice2=='V'||choice2=='v'){
            system ("cls");
            printf ("Fare For Ventilator: INR15000/DAY\n[NOTE-Prices Of MEDECINES,TESTS NOT INCLUDED]\n<<Prices Are GST EXCLUSIVE>>\n");
        }

        else {
            system ("cls");
            printf ("<<Try 'G' OR 'I' or 'V'>>\n");
        }


    }
    else if (choice1=='N'||choice1=='n'){
        system ("cls");
    }
    else {
        printf ("<<Try 'Y' OR 'N'>>\n");
    }


}





void vacc_add(){

    struct vacc_add{            //Structures are used to keep date and vaccine stock data
        char date[1000];
        int covaxine;
        int covishield;
        int sputnik;
        int registered;
    };

    struct vacc_add e1;
    struct vacc_add *ptr;
    ptr=&e1;
    
    


    FILE *fp;
    fp=fopen("vacc.csv","a+");
    printf("Enter the date:");
    scanf("%s",&ptr->date);             //Pointers are used to indicate to the final arrays 
    printf("\nEnter no. of Covaxine Vaccine you want to add-");
    scanf("%d",&ptr->covaxine);             //Pointers are used to indicate to the final arrays 
     printf("\nEnter no. of Covishield Vaccine you want to add-");
    scanf("%d",&ptr->covishield);           //Pointers are used to indicate to the final arrays 
     printf("\nEnter no. of sputnik Vaccine you want to add-");
    scanf("%d",&ptr->sputnik);              //Pointers are used to indicate to the final arrays 
    printf("\nNo.of patients registered on %s date",ptr->date);
    scanf("%d",&ptr->registered);              //Pointers are used to indicate to the final arrays 
    fprintf (fp,"%s,%d,%d,%d,%d\n",ptr->date,ptr->covaxine,ptr->covishield,ptr->sputnik,ptr->registered);

    fclose(fp);

    printf("Record Added");
}





void Vacc_search_2(){               //This is to search through Vaccine stock data and insert data into arrays

    char str[100]="";
    char c=' ';
    char z=' ';
    char c1=' ';
    int r,ro,x,y;
    ro=x=y=r=0;


    struct vac1 vac[1000];




    FILE *ptr;                               //This Block of code is to Count Number of Columns
    ptr=fopen("vacc.csv","r");
    for(int i=0;z!='\n';i++){
        fscanf(ptr,"%c",&z);
        //printf("%c",z);
        if(z==','){
            ccount=ccount+1;
        }
        else if(z==EOF){
            break;
        }
    }
    ccount=ccount+1;//to make count the number of fields
    //printf("fields:%d\n",ccount);
    fclose(ptr);

    FILE *ptr2;                          //This block of code is to Count Number of Rows and Characters in the file
    ptr2=fopen("vacc.csv","r");
    for(int i=0;c!=EOF;i++){
    c=fgetc(ptr);
    //printf("%c",c);
    if(c!='\n'){
        wcount=wcount+1;
    }
        else if(c==EOF){
            printf("EOF found\n");
        }
        else{
            rcount=rcount+1;
        }



    }
    wcount=wcount+1;
    printf("\nRow Count:%d\n",rcount);

    fclose(ptr);




    FILE *ptr1;                                            //THis Block of code is to Read charcter by caracter from file and put it into Arrays
    ptr1=fopen("vacc.csv","r");                           //According to their respective data type
    //printf("1\n");


    printf("Character Count:%d\n",wcount);
    for(int i=0;c1!=EOF;i++){                               //Here this loop is made to Run till EOF(End of file)
        c1=fgetc(ptr1);
        //printf("%c",c1);
        
        if((c1==',' || c1=='\n')||(c1==EOF) ){
            //printf("%s ",str);
            if(r==0){               //vaccine date
                strcpy(vac[ro].date_r,str);
                strcpy(str,"");
                r++;
            }

            else if(r==1){          //Covaxine Stock
                vac[ro].covaxine_r=atoi(str);
                strcpy(str,"");
                r++;
            }

            else if(r==2){
                // sscanf(str,"%d",&x);
                //printf("%s\n",str);
                vac[ro].covishield_r=atoi(str); //Covisheild stock
                strcpy(str,"");
                r++;
            }
            else if(r==3){
                vac[ro].sputnik_r=atoi(str);    //Sputnik stock
                strcpy(str,"");
                r++;
            }
            else if(r==4){
                vac[ro].registered_r=atoi(str);  //Registred people
                strcpy(str,"");
                r=0;
                ro=ro+1;
            }
        }

    else{
            strncat(str,&c1,1);
        }
    }
    
    printf("\n");
    fclose(ptr1);



    char date_entered[12];
    printf("Enter date:");
    scanf("%s",&date_entered);

    for (int i=0;i<rcount;i++){
        //printf("%s: %s \n",fields_vacc1[0],vac[i].date_r);
        if(0==strcmp(date_entered,vac[i].date_r)){
            id_pos=i;
            break;
        }
    }


    if(id_pos!=-1){             //Display Data Stock
        printf("%s: %s \n",fields_vacc1[0],vac[id_pos].date_r);
        printf("%s: %d \n",fields_vacc1[1],vac[id_pos].covaxine_r);
        printf("%s: %d \n",fields_vacc1[2],vac[id_pos].covishield_r);
        printf("%s: %d \n",fields_vacc1[3],vac[id_pos].sputnik_r);
        printf("%s: %d \n",fields_vacc1[4],vac[id_pos].registered_r);

        printf("====================================================\n");

    }
    else{
        printf("<<<<No Match Found!>>>>\n");
    }
    system("pause");
}





int main (){                    //This is where all the Function flow is setted using Switch Case and IF Else  Loops

    int res,res2=1;
    printf("\n");
    printf("====================================================\n");
    res=adm_login();            //Here it will Go for admin athentication

//printf("\a");
    while(res2!=0){
        if(0==res){
            firstscreen();          //First screen for menu
            printf("====================================================\n");
            printf("Input>>>>");
            scanf("%d",&choice);

            printf("====================================================\n");
            switch(choice){

            //if(choice==1){          //patient Records
            case 1:
                system("cls");
                printf("====================================================\n");
                printf("Press 1 For New Patient Details:-\n");
                printf("Press 2 For Searching Patient Details:-\n");
                printf("Press 3 For Editing Patient Record:-\n");
                printf("====================================================\n");
                printf("Input>>>>");
                scanf("%d",&choice2);

                system("cls");
                printf("====================================================\n");


                if(choice2==1){         //New patient entry
                    readfile();
                    p_rec();
                }
                else if(choice2==2){    //Search Patient Record using Patient ID
                    title();
                    readfile();
                    idsearch();
                }
                else if(choice2==3){    //Edit patient Record using Patient ID
                    title();
                    readfile();
                    idsearch();
                }
                break;
            //}
            
            //else if(choice==2){             //Doctor Records
            case 2:                      //For doctor Records
                system("cls");
                printf("====================================================\n");
                printf("Press 1 For New Doctor Details:-\n");
                printf("Press 2 For Searching Doctor Details:-\n");
                printf("Press 3 For Editing Doctor Record:-\n");
                printf("====================================================\n");
                printf("Input>>>>");
                scanf("%d",&choice2);

                system("cls");
                printf("====================================================\n");

                if(choice2==1){       //For New doctor addtion
                    d_read();
                    d_rec();
                }

                else if(choice2==2){        //For searching doctor records using Doctor ID
                    d_read();
                    d_display();
                }

                else if(choice2==3){           //For editing Doctor Records
                    d_read();
                    d_filedit();
                    d_write();
                }
                break;
            //}
            
            
            
           // else if(choice==3){         //Bed managment
            case 3:
                //system("cls");
                printf("====================================================\n");

                bed();                      //For Bed availablity 
                break;
            //}

            //else if(choice==4){         //Vaccination Records

            case 4:                       //New person vaccine registration 
                system("cls");
                printf("====================================================\n");
                printf("Press 1 For New Vaccine Registration Details:-\n");
                printf("Press 2 For Searching Vaccination Details:-\n");
                printf("Press 3 For Editing Vaccination Record:-\n");
                printf("====================================================\n");
                printf("Input>>>>");
                scanf("%d",&choice2);

                system("cls");
                printf("====================================================\n");

        
                if (choice2==1){            //New vaccine Benificiary Registration 
                    add_ben();
                }

                else if(choice2==2){            //Searching vaccine benifitiary details
                    readfile_vc();
                    idsearch_vc();
                }

                else if(choice2==3){                //Editing vaccine benifitiary details
                    readfile_vc();
                    idsearch_vc();
                }
                break;
            //}

            //else if(choice==5){         //Vaccine stocks
            case 5:    
                system("cls");
                printf("====================================================\n");
                
                printf("Press 1 For Vaccine Stocks Details:-\n");           
                printf("Press 2 For Searching Vaccine Stocks:-\n");
                
                printf("====================================================\n");
                printf("Input>>>>");
                scanf("%d",&choice2);

                system("cls");
                printf("====================================================\n");

        
                if (choice2==1){            //vaccine stock addition 
                    vacc_add();
                }

                else if(choice2==2){        //Vaccine stock searching by date
                    Vacc_search_2();
                }

                break;
            //}
            }   

        }   

        else{
            printf("<<<<<Wrong Credentials>>>>>");
        }
        

        printf("<<TO EXIT PRESS 0>>");
        //here the varibles are destructed for the next cycle
        scanf("%d",&res2);
        system("pause");
        system("cls");
        ccount=wcount=rcount=0;     

        a_count=ventcount=gencount=icucount=0;

        choice=choice2=0;
        id_pos=-1; 
        att=0;    

    }
    
    return 0;
}



