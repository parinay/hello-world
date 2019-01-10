#include<stdio.h>
#define NFRAMES 3

void initialize(int frames[])
{
	int i;
	for(i = 0; i < NFRAMES; ++i) {
		frames[i] = -1;
	}
}
int pageCanbeAdded(int frames[])
{
	int index = -1;
	int i;

	for(i=0; i < NFRAMES; i++) {
		if(frames[i] == -1) {
			index = i;
			break;
		}
	}
	return(index);
}
int pageExists(int frames[], int page)
{
	int i;
	int index = -1;
	for(i=0; i< NFRAMES; i++) {
		if(frames[i] == page) {
			index = i;
			break;
		}
	}
	return(index);
}
int findLRU(int count[])
{
	int i, minimum = count[0], pos = 0;
	for(i = 1; i < NFRAMES;i++){
		if(count[i] < minimum){
			minimum = count[i];
			pos = i;
		}
	}
	return (pos);
}
int main()
{
	int pages[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
	int frames[NFRAMES];

	int counter = 0;
	int usageCount[NFRAMES];
	int pageadd, pagehit, i, j, index, pagefaults, frameCounter;

	int no_of_pages =  sizeof(pages) / sizeof(pages[0]);
	printf("No. of pages - %d\nNo. of frame - %d \n", no_of_pages, NFRAMES);

	pagefaults=0;


	//initialize frames with -1
	initialize(frames);

	for(i = 0; i < no_of_pages; ++i) {
		pageadd=0;
		pagehit=0;

		// check if empty frame exists i.e. pageCanbeAdded
		if (pageadd == 0) {
			if ((frameCounter = pageCanbeAdded(frames)) != -1) {
				counter++;
				pagefaults++;
				frames[frameCounter] = pages[i];
				usageCount[frameCounter] = counter;
				pageadd = 1;
			}
		}
		// check if page exists in frames i.e. pageHit.
		if ((frameCounter = pageExists(frames,pages[i])) != -1) {
			counter++;
			usageCount[frameCounter] = counter;
			pageadd = pagehit = 1;
		}
		// page doesn't exists in frame && page frame not empty
		//thus find page to be relpaced.

		if(pagehit == 0){
			index = findLRU(usageCount);
			counter++;
			pagefaults++;
			frames[index] = pages[i];
			usageCount[index] = counter;
		}
	}

	printf("No. of Page Faults = %d\n", pagefaults);
	return 0;
}
