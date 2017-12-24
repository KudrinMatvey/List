#pragma once
#include <iostream>
using namespace std;
template <class T>
struct TLink {
	T val;
	TLink *pNext;
};
template <class T>
class TList {
	TLink <T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int size, pos;
public:
	TList() {
		pFirst = pLast = pCurr = pStop = NULL;
		size = 0;
		pos = -1;
	}

	void OrderedIn(T a) {
		if (IsEmpty())
		{
			InsElem(a);
			return;
		}
		for (Reset(); !IsEnd(); GoNext())
		{
			if (pCurr->val >= a) {
				InsCurr(a);
				return;
			}
		}
			if (pCurr == pStop) InsElem(a);
			return;
		
	}

	void InsFirst(T a) {
		TLink<T> *tmp = new TLink<T>;
		tmp->val = a;
		if (size == 0) {
			pCurr = pFirst = pLast = tmp;
			tmp->pNext = pStop;
			pos = 0;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
			pos++;
			if (size == 1) pPrev = pFirst;
		}
		size++;
	}

	void InsCurr(T a) {
		if (pCurr == pFirst) InsFirst(a);
		else {
			TLink<T> *tmp = new TLink<T>;
			tmp->val = a;
			tmp->pNext = pCurr;
			pPrev->pNext = tmp;
			pCurr = tmp;
			size++;
		}
	}

	void InsElem(T a) {
		if (pFirst == pStop) InsFirst(a);
		else {
			TLink<T> *tmp = new TLink<T>;
			tmp->val = a;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			pCurr = pLast;
			size++;
		}
	}

	void DelFirst() {
		if (size == 1) {
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = pStop;
		pCurr -> pNext = pFirst;
		}
		else {
			TLink<T> *tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		pos--;
		size--;
	}

	void DelCurr() {
		if (pCurr == pFirst) DelFirst();
		else if (pCurr->pNext == pStop) {
			for (Reset(); !IsEnd(); GoNext())
			{
				if (pCurr == pFirst && pCurr->pNext == pLast)
				{
					delete pFirst->pNext;
					pFirst->pNext = pStop;
					pLast = pFirst;
					pCurr = pFirst;
					pos--;
					size--;
					return;
				}
				else if (pCurr->pNext->pNext == pLast) {
					delete pLast;
					pCurr->pNext->pNext = pStop;
					pLast = pCurr->pNext;
					pos--;
					size--;
					return;
				}
			}
		}
		else {
			pCurr = pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext = pCurr;
			size--;
		}
	}

	T GetCurrentVal() {
		return pCurr->val;
	}

	void Reset() {
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}

	void GoNext() {
		
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			pos++;
	
	}

	bool IsEnd() {
		if (pCurr == pStop) return 1;
		else return 0;
	}

	bool IsEmpty() {
		if (pFirst == pStop) return 1;
		return 0;
	}

	T operator[](int m) {
		for (Reset(); !IsEnd(); GoNext()) {
			if (pos == m - 1)
				return pCurr->val;
		}
	}
};