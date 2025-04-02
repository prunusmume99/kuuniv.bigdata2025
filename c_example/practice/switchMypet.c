#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PETS 10
#define MAX_NAME_LENGTH 50
#define FILE_NAME "pets.dat"

// 펫 정보를 저장할 구조체
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int hunger;
    int cleanliness;
    int fun;
    int sleep;
    time_t creation_time;
} Pet;

// 함수 프로토타입 선언
void clear_input_buffer(void);
void print_pet_status(Pet *pet);
void update_pet_status(Pet *pet, int hunger_change, int cleanliness_change, int fun_change, int sleep_change);
void pet_menu(Pet *pet);
void display_pet_list(void);
void create_new_pet(void);
void petSelectionMenu(void);
void save_pets(void);
void load_pets(void);

Pet pets[MAX_PETS];
int pet_count = 0;

void clear_input_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void print_pet_status(Pet *pet) {
    printf("\n[%s의 상태]\n", pet->name);
    printf("나이: %d\n", pet->age);
    printf("배고픔: %d / 100\n", pet->hunger);
    printf("청결도: %d / 100\n", pet->cleanliness);
    printf("재미: %d / 100\n", pet->fun);
    printf("수면: %d / 100\n", pet->sleep);
}

void update_pet_status(Pet *pet, int hunger_change, int cleanliness_change, int fun_change, int sleep_change) {
    pet->hunger += hunger_change;
    pet->cleanliness += cleanliness_change;
    pet->fun += fun_change;
    pet->sleep += sleep_change;
    if (pet->hunger > 100) pet->hunger = 100;
    if (pet->cleanliness > 100) pet->cleanliness = 100;
    if (pet->fun > 100) pet->fun = 100;
    if (pet->sleep > 100) pet->sleep = 100;
    print_pet_status(pet);
}

void pet_menu(Pet *pet) {
    int choice;
    while (1) {
        printf("\n┌───────────────────────────────────────────┐\n");
        printf("│              마이펫 관리 메뉴             │\n");
        printf("├───────────────────────────────────────────┤\n");
        printf("│ 1. 상태 확인                              │\n");
        printf("│ 2. 배고픔 채우기                          │\n");
        printf("│ 3. 청결도 관리                            │\n");
        printf("│ 4. 재미 활동                              │\n");
        printf("│ 5. 수면                                   │\n");
        printf("│ 6. 돌아가기                               │\n");
        printf("└───────────────────────────────────────────┘\n");
        printf("원하시는 작업의 번호를 입력하세요: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                print_pet_status(pet);
                break;
            case 2: {
                int food_choice;
                printf("\n┌───────────────────────────────────────────┐\n");
                printf("│              배고픔을 채우기              │\n");
                printf("├───────────────────────────────────────────┤\n");
                printf("│ 1. 밥주기                                 │\n");
                printf("│ 2. 간식주기                               │\n");
                printf("└───────────────────────────────────────────┘\n");
                printf("원하시는 선택의 번호를 입력하세요: ");
                scanf("%d", &food_choice);
                clear_input_buffer();

                if (food_choice == 1) {
                    update_pet_status(pet, 10, 0, 0, 0);
                    printf("%s: 맛있다! 배부르다! (배고픔 +10)\n", pet->name);
                } else if (food_choice == 2) {
                    update_pet_status(pet, 5, 0, 0, 0);
                    printf("%s: 간식 최고! 고마워! (배고픔 +5)\n", pet->name);
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;
            }
            case 3: {
                int clean_choice;
                printf("\n┌───────────────────────────────────────────┐\n");
                printf("│              청결도 관리                 │\n");
                printf("├───────────────────────────────────────────┤\n");
                printf("│ 1. 양치하기                               │\n");
                printf("│ 2. 목욕하기                               │\n");
                printf("│ 3. 세수하기                               │\n");
                printf("└───────────────────────────────────────────┘\n");
                printf("원하시는 선택의 번호를 입력하세요: ");
                scanf("%d", &clean_choice);
                clear_input_buffer();

                if (clean_choice == 1) {
                    update_pet_status(pet, 0, 5, 0, 0);
                    printf("%s: 상쾌하다! (청결도 +5)\n", pet->name);
                } else if (clean_choice == 2) {
                    update_pet_status(pet, 0, 10, 0, 0);
                    printf("%s: 깨끗해졌다! (청결도 +10)\n", pet->name);
                } else if (clean_choice == 3) {
                    update_pet_status(pet, 0, 3, 0, 0);
                    printf("%s: 얼굴이 빛난다! (청결도 +3)\n", pet->name);
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;
            }
            case 4: {
                int fun_choice;
                printf("\n┌───────────────────────────────────────────┐\n");
                printf("│               재미 활동                  │\n");
                printf("├───────────────────────────────────────────┤\n");
                printf("│ 1. 책 읽기                                │\n");
                printf("│ 2. 게임하기                               │\n");
                printf("│ 3. 공놀이하기                             │\n");
                printf("└───────────────────────────────────────────┘\n");
                printf("원하시는 선택의 번호를 입력하세요: ");
                scanf("%d", &fun_choice);
                clear_input_buffer();

                if (fun_choice == 1) {
                    update_pet_status(pet, 0, 0, 2, 0);
                    printf("%s: 책이 재미있어! (재미 +2)\n", pet->name);
                } else if (fun_choice == 2) {
                    update_pet_status(pet, 0, 0, 5, 0);
                    printf("%s: 게임 신난다! (재미 +5)\n", pet->name);
                } else if (fun_choice == 3) {
                    update_pet_status(pet, 0, 0, 3, 0);
                    printf("%s: 공놀이 즐겁다! (재미 +3)\n", pet->name);
                } else {
                    printf("잘못된 선택입니다.\n");
                }
                break;
            }
            case 5:
                update_pet_status(pet, 0, 0, 0, 10);
                printf("%s: 낮잠 자니 기분 최고! (수면 +10)\n", pet->name);
                break;
            case 6:
                printf("펫 관리 메뉴로 돌아갑니다.\n");
                return;
            default:
                printf("잘못된 선택입니다.\n");
                break;
        }
    }
}

// 기존 펫 목록을 ASCII 아트로 출력하는 함수
void display_pet_list(void) {
    printf("\n==================== 펫 목록 ====================\n");
    for (int i = 0; i < pet_count; i++) {
        char timeStr[26];
        ctime_r(&pets[i].creation_time, timeStr);
        timeStr[strcspn(timeStr, "\n")] = '\0';
        printf("%d. %-10s  %s생  /  상태: 배고픔 %d, 청결 %d, 재미 %d, 수면 %d\n",
               i + 1, pets[i].name, timeStr,
               pets[i].hunger, pets[i].cleanliness, pets[i].fun, pets[i].sleep);
    }
    printf("=================================================\n");
}

// 새로운 펫을 생성하는 함수
void create_new_pet(void) {
    Pet new_pet;
    time_t now;
    time(&now);
    printf("새로운 펫의 이름을 입력하세요: ");
    fgets(new_pet.name, sizeof(new_pet.name), stdin);
    new_pet.name[strcspn(new_pet.name, "\n")] = '\0';
    new_pet.age = 0;
    new_pet.hunger = 50;
    new_pet.cleanliness = 50;
    new_pet.fun = 50;
    new_pet.sleep = 50;
    new_pet.creation_time = now;
    pets[pet_count] = new_pet;
    pet_count++;
    save_pets();
    printf("새로운 펫 '%s'가 생성되었습니다!\n", new_pet.name);
}

// 펫 정보를 파일에 저장하는 함수 (이진 모드)
void save_pets(void) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file != NULL) {
        fwrite(&pet_count, sizeof(int), 1, file);
        fwrite(pets, sizeof(Pet), pet_count, file);
        fclose(file);
    } else {
        printf("펫 정보를 저장하는 데 실패했습니다.\n");
    }
}

// 펫 정보를 파일에서 불러오는 함수 (이진 모드)
void load_pets(void) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file != NULL) {
        fread(&pet_count, sizeof(int), 1, file);
        fread(pets, sizeof(Pet), pet_count, file);
        fclose(file);
    }
}

// 펫 선택 메뉴: 기존 펫을 불러오거나 새 펫을 생성하는 메뉴
void petSelectionMenu(void) {
    int option;
    printf("\n==================== 펫 선택 메뉴 ====================\n");
    printf("1. 기존 펫 불러오기\n");
    printf("2. 새 펫 만들기\n");
    printf("=====================================================\n");
    printf("원하시는 옵션 번호를 입력하세요: ");
    scanf("%d", &option);
    clear_input_buffer();

    if (option == 1) {
        load_pets();
        if (pet_count == 0) {
            printf("저장된 펫이 없습니다. 새 펫을 생성합니다.\n");
            create_new_pet();
        } else {
            display_pet_list();
            int select;
            printf("불러올 펫 번호를 입력하세요: ");
            scanf("%d", &select);
            clear_input_buffer();
            if (select < 1 || select > pet_count) {
                printf("잘못된 번호입니다. 새 펫을 생성합니다.\n");
                create_new_pet();
            } else {
                printf("\n%s 펫을 불러왔습니다.\n", pets[select - 1].name);
                pet_menu(&pets[select - 1]);
                save_pets();
            }
        }
    } else if (option == 2) {
        create_new_pet();
        pet_menu(&pets[pet_count - 1]);
        save_pets();
    } else {
        printf("잘못된 옵션입니다.\n");
    }
}

int main(void) {
    int main_choice;
    while (1) {
        printf("\n==================== 펫 키우기 메인 메뉴 ====================\n");
        printf("1. 펫 선택하기 (기존 펫 불러오기)\n");
        printf("2. 새 펫 만들기\n");
        printf("3. 종료\n");
        printf("-------------------------------------------------------------\n");
        printf("원하시는 옵션 번호를 입력하세요: ");
        scanf("%d", &main_choice);
        clear_input_buffer();

        if (main_choice == 1 || main_choice == 2) {
            petSelectionMenu();
        } else if (main_choice == 3) {
            printf("프로그램을 종료합니다.\n");
            exit(0);
        } else {
            printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}
