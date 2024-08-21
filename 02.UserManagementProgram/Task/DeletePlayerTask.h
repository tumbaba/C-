#pragma once
struct FDeletePlayerTask
{
	FDeletePlayerTask() noexcept;
	FDeletePlayerTask(const FDeletePlayerTask&) = delete;
	FDeletePlayerTask& operator=(const FDeletePlayerTask&) = delete;
};