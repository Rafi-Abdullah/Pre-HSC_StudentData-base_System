#ifndef PROTOTYPES
#define PROTOTYPES

typedef enum {FIRST_NAME , LAST_NAME ,SCHOOL_NAME, NUMBER , BLOOD_G , SIM} search_t;
enum {AIRTEL, BANGLA, ROBI, TEL, GP};

typedef struct
  {
    char f_name[10];
    char l_name[10];
    char nick_name[10];
    char school[10];
    char bld_grp[4];
    char number[20];
    char mail[25];
    float GPA;
    char scholarship[4];
    char payment[6];
    int dues;
    int year;
    int id;

    char date[30];
  } DATA ;

//function prototypes ::
void last_status();

void Heading();
void HeadingDUES();

void addEntry();
void displayAll();
void displaySrM(); //display single or multiple
void display(int);

void modify();

void payment_FULL();
void payment_DUES();

void Search(char *text,search_t type);
void Search_sim(int);

void deleteENTRY();

void writeToFile();
void readFromFile();

void remove_FILE();

char mygetch();

#endif
