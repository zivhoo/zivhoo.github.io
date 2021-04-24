# 

## Data
+ CharacterStatsDefinition

+ AttackDefinition
        Weapon          武器攻击
            weaponPreb  
        Spell 魔法攻击
        Aoe

+ ItemDefinition
        itemMaterial
        itemIcon
        itemSpawnObject<ItemPickUp>
        weaponSlotObject<Weapon>




## Monobehaviour
+ ItemPickUp
    ItemDefinition
    CharacterStats

    UseItem()
    StoreItemInInventory()

+ CharacterInventory
    itemsInInventory

    StoreItem()
    TryPickUp()
    AddItemToInv()

+ SpawnItem
    List<ItemDefinition> ids
    CreateSpawn()
        return ItemDefinition.itemSpawnObject

+ CharacterStats
    characterWeaponSlot

战利品
ItemDefinition
ItemPickUp
SpawnItem

背包
InventoryEntry
    ItemPickUp
    stackSize
    inventorySolt
    iconSprite
ChatacterInventory

战斗
AttackDefinition
    Weapon
    Spell
    AOE
Attack
IAttackable
    AttackedScrollingText
    AttackedTakeDamage
    AttackedForce

统计
ChatacterStatsDefinition
ChatacterStats
