// Fill out your copyright notice in the Description page of Project Settings.


#include "xResource.h"

int AxResource::getResource(int _count)
{
	if (this->count == 0)
		return 0;

	if (_count > this->count) {
		this->count = 0;
		this->on_resource_empty.Broadcast();
		this->is_empty = true;

		return this->count;
	}

	this->count = this->count - _count;

	if (this->count == 0) {
		this->on_resource_empty.Broadcast();
		this->is_empty = true;
	} else {
		this->on_get_resource.Broadcast();
	}


	return _count;
}

FVector AxResource::getDockingLocation_Implementation() const
{
	return FVector();
}

