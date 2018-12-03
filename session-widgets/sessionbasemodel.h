#ifndef SESSIONBASEMODEL_H
#define SESSIONBASEMODEL_H

#include "userinfo.h"

#include <QObject>
#include <memory>

class SessionBaseModel : public QObject
{
    Q_OBJECT
public:
    enum AuthType {
        LockType,
        LightdmType
    };

    enum PowerAction {
        RequireNormal,
        RequireShutdown,
        RequireRestart,
        RequireSuspend,
    };

    enum ModeStatus {
        PasswordMode,
        UserMode,
        SessionMode,
        PowerMode
    };

    explicit SessionBaseModel(AuthType type, QObject *parent = nullptr);

    inline AuthType currentType() const { return m_currentType; }
    inline std::shared_ptr<User> currentUser() { return m_currentUser; }
    inline std::shared_ptr<User> lastLogoutUser() const { return m_lastLogoutUser; }

    std::shared_ptr<User> findUserByUid(const uint uid) const;
    const QList<std::shared_ptr<User>> userList() const { return m_userList; }
    const QList<std::shared_ptr<User>> logindUser();

    void userAdd(std::shared_ptr<User> user);
    void userRemoved(std::shared_ptr<User> user);
    void setCurrentUser(std::shared_ptr<User> user);
    void setLastLogoutUser(const std::shared_ptr<User> &lastLogoutUser);

    inline QString sessionKey() const { return m_sessionKey; }
    void setSessionKey(const QString &sessionKey);

    inline PowerAction powerAction() const { return m_powerAction; }
    void setPowerAction(const PowerAction &powerAction);

    ModeStatus currentModeState() const { return m_currentModeState; }
    void setCurrentModeState(const ModeStatus &currentModeState);

    inline bool hasVirtualKB() { return m_hasVirtualKB; }
    void setHasVirtualKB(bool hasVirtualKB);

signals:
    void onUserAdded(std::shared_ptr<User> user);
    void onUserRemoved(const uint uid);
    void currentUserChanged(std::shared_ptr<User> user);
    void authFaildMessage(const QString &message);
    void authFaildTipsMessage(const QString &message);
    void authFinished(bool success);
    void onPowerActionChanged(PowerAction poweraction);
    void onSessionKeyChanged(const QString &sessionKey);
    void onLogindUserChanged();
    void showUserList();
    void show();
    void onStatusChanged(ModeStatus status);
    void onUserListChanged(QList<std::shared_ptr<User>> list);
    void hasVirtualKBChanged(bool hasVirtualKB);

private:
    AuthType m_currentType;
    QList<std::shared_ptr<User>> m_userList;
    std::shared_ptr<User> m_currentUser;
    std::shared_ptr<User> m_lastLogoutUser;
    QString m_sessionKey;
    PowerAction m_powerAction;
    ModeStatus m_currentModeState;
    bool m_hasVirtualKB;
};

#endif // SESSIONBASEMODEL_H
