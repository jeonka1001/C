//
//  phoneNumBook.h
//  Day_0601
//
//  Created by 전경안 on 2020/06/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef phoneNumBook_h
#define phoneNumBook_h

typedef struct Person Person;

Person* personInit(char* _name,char* _num);

void setNumber(Person *p,char *_num);
void setName(Person *p,char *_name);
char* getNum(Person *p);
char* getName(Person* p );
char* toString(void *o);

int freePerson(void *o);


#endif /* phoneNumBook_h */
