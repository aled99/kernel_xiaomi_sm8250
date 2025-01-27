/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2016-2019, The Linux Foundation. All rights reserved. */

#ifndef _CNSS_DEBUG_H
#define _CNSS_DEBUG_H

#include <linux/ipc_logging.h>
#include <linux/printk.h>

#define CNSS_IPC_LOG_PAGES		32

extern void *cnss_ipc_log_context;
extern void *cnss_ipc_log_long_context;

#define cnss_ipc_log_string(_x...) ipc_log_string(cnss_ipc_log_context, _x) ;

#define cnss_ipc_log_long_string(_x...) ipc_log_string(cnss_ipc_log_long_context, _x);
	

#define cnss_pr_err(_fmt, ...) cnss_ipc_log_string("%scnss: " _fmt, "", ##__VA_ARGS__);

#define cnss_pr_warn(_fmt, ...) cnss_ipc_log_string("%scnss: " _fmt, "", ##__VA_ARGS__);

#define cnss_pr_info(_fmt, ...) cnss_ipc_log_string("%scnss: " _fmt, "", ##__VA_ARGS__);

#define cnss_pr_dbg(_fmt, ...) cnss_ipc_log_string("%scnss: " _fmt, "", ##__VA_ARGS__); 

#define cnss_pr_vdbg(_fmt, ...) cnss_ipc_log_long_string("%scnss: " _fmt, "",  ##__VA_ARGS__); 

#ifdef CONFIG_CNSS2_DEBUG
#define CNSS_ASSERT(_condition) do {					\
		if (!(_condition)) {					\
			cnss_pr_err("ASSERT at line %d\n",		\
				    __LINE__);				\
			BUG();						\
		}							\
	} while (0)
#else
#define CNSS_ASSERT(_condition) do {					\
		if (!(_condition)) {					\
			cnss_pr_err("ASSERT at line %d\n",		\
				    __LINE__);				\
			WARN_ON(1);					\
		}							\
	} while (0)
#endif

#define cnss_fatal_err(_fmt, ...)					\
	cnss_pr_err("fatal: " _fmt, ##__VA_ARGS__)

int cnss_debug_init(void);
void cnss_debug_deinit(void);
int cnss_debugfs_create(struct cnss_plat_data *plat_priv);
void cnss_debugfs_destroy(struct cnss_plat_data *plat_priv);

#endif /* _CNSS_DEBUG_H */
