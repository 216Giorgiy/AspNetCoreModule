#pragma once

class IN_PROCESS_HANDLER : public REQUEST_HANDLER
{
public:
    IN_PROCESS_HANDLER(
        _In_ IHttpContext *pW3Context,
        _In_ APPLICATION  *pApplication);

    ~IN_PROCESS_HANDLER();

    __override
    REQUEST_NOTIFICATION_STATUS
    OnExecuteRequestHandler();

    __override
    REQUEST_NOTIFICATION_STATUS
    OnAsyncCompletion(
        DWORD       cbCompletion,
        HRESULT     hrCompletionStatus
    );

    PVOID
    QueryManagedHttpContext(
        VOID
    );

    VOID
    SetManangedHttpContext(
        PVOID pManagedHttpContext
    );

    IHttpContext*
    QueryHttpContext(
        VOID
    );

    BOOL
    QueryIsManagedRequestComplete(
        VOID
    );

    VOID
    IndicateManagedRequestComplete(
        VOID
    );

    REQUEST_NOTIFICATION_STATUS
    QueryAsyncCompletionStatus(
        VOID
    );

    VOID
    SetAsyncCompletionStatus(
        REQUEST_NOTIFICATION_STATUS requestNotificationStatus
    );

private:
    PVOID m_pManagedHttpContext;
    BOOL m_fManagedRequestComplete;
    REQUEST_NOTIFICATION_STATUS m_requestNotificationStatus;
};