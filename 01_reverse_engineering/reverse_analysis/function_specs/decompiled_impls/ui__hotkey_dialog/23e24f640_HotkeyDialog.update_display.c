/* ===== 23e24f640 ui.hotkey_dialog:199 ===== */
/* ghidra_name=FUN_23e24f640 entry=23e24f640 size=1679 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e24f640(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  code *pcVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  bool bVar14;
  undefined8 uVar15;
  longlong lStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  plVar9 = _DAT_23eeb01c8;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb01c8 == (longlong *)0x0) {
LAB_23e24f683:
    _DAT_23eeb01c8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb01c0,DAT_23eeb0268,0x20);
  }
  else {
    lVar11 = *_DAT_23eeb01c8;
    if (1 < lVar11) {
      *_DAT_23eeb01c8 = lVar11 + -1;
      goto LAB_23e24f683;
    }
    if (_DAT_23eeb01c8[2] != 0) {
      *_DAT_23eeb01c8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e24f683;
    }
  }
  plVar3 = _DAT_23eeb01c8;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb01c8 + 9;
  lVar12 = *(longlong *)(lVar11 + 8);
  _DAT_23eeb01c8[0xf] = lVar12;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  iVar4 = FUN_23e8be270(param_1,plVar2,DAT_23ed6ce48);
  if (iVar4 == -1) {
LAB_23e24f980:
    uVar13 = *(undefined8 *)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    lVar12 = *(longlong *)(param_1 + 0x60);
    uVar15 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e24f99d:
    lStack_78 = lVar12;
    uStack_70 = uVar15;
    uStack_68 = uVar13;
    FUN_23a35d6b0(&lStack_78);
  }
  else {
    if (iVar4 != 0) {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23ed6ce48);
      if (plVar9 == (longlong *)0x0) {
LAB_23e24f9c0:
        lVar12 = *(longlong *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = *(undefined8 *)(param_1 + 0x70);
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e24f99d;
      }
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead730);
      plVar8 = (longlong *)0x0;
      if (plVar7 != (longlong *)0x0) {
        *(undefined4 *)(plVar3 + 5) = 0xce;
        plVar5 = (longlong *)FUN_23e94bb80(param_1,plVar7,_DAT_23eead738);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar5 == (longlong *)0x0) goto LAB_23e24f9c0;
        iVar4 = FUN_23a35f020(plVar5);
        lVar11 = *plVar5 + -1;
        if (iVar4 == -1) {
          lVar12 = *(longlong *)(param_1 + 0x60);
          uVar15 = *(undefined8 *)(param_1 + 0x68);
          uVar13 = *(undefined8 *)(param_1 + 0x70);
          plVar8 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar5 = lVar11;
          if (lVar11 == 0) {
            (**(code **)(plVar5[1] + 0x30))(plVar5);
          }
          goto LAB_23e24f99d;
        }
        *plVar5 = lVar11;
        if (lVar11 == 0) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        if (iVar4 == 0) {
LAB_23e24f8c0:
          plVar8 = (longlong *)FUN_23e8d7870(param_1,_DAT_23eead748);
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead750);
          if (plVar7 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0xe3;
            pcVar6 = (code *)FUN_23e91a870(param_1,plVar7);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            if (pcVar6 != (code *)0x0) {
              pcVar10 = (code *)FUN_23e973620(plVar8,plVar9);
              lVar11 = *(longlong *)pcVar6;
              if (pcVar10 == (code *)0x0) {
                lVar12 = *(longlong *)(param_1 + 0x60);
                if (lVar12 != 0) {
                  *(longlong *)pcVar6 = lVar11 + -1;
                  if (lVar11 + -1 == 0) {
                    (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
                    lVar12 = *(longlong *)(param_1 + 0x60);
                  }
                  uVar13 = *(undefined8 *)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar15 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e24f99d;
                }
                pcVar10 = pcVar6;
                if (lVar11 == 0) {
                  (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
                }
              }
              else {
                *(longlong *)pcVar6 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(*(longlong *)(pcVar6 + 8) + 0x30))(pcVar6);
                }
              }
LAB_23e24fb69:
              lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar3 = *(longlong **)(lVar11 + 0x28);
              plVar7 = (longlong *)plVar3[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
              *(undefined4 *)(plVar3 + 8) = 0xffffffff;
              if (plVar7 != (longlong *)0x0) {
                plVar3[2] = 0;
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))();
                }
              }
              *plVar3 = *plVar3 + -1;
              if (*plVar3 == 0) {
                (**(code **)(plVar3[1] + 0x30))(plVar3);
              }
              plVar3[0xf] = 0;
              goto LAB_23e24f7b6;
            }
          }
        }
        else {
          plVar7 = (longlong *)FUN_23e8bd600(param_1,plVar9);
          plVar8 = (longlong *)0x0;
          if (plVar7 == (longlong *)0x0) goto LAB_23e24fa80;
          lVar11 = *plVar7 + -1;
          if (plVar7[2] == 1) {
            if (*(uint *)(plVar7 + 3) != 3) {
              bVar14 = *(uint *)(plVar7 + 3) < 3;
              goto LAB_23e24fa15;
            }
            *plVar7 = lVar11;
            if (lVar11 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
          }
          else {
            bVar14 = SUB81((ulonglong)(plVar7[2] + -1) >> 0x3f,0);
LAB_23e24fa15:
            *plVar7 = lVar11;
            if (lVar11 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            if (bVar14 == false) goto LAB_23e24f8c0;
          }
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead740);
          plVar8 = (longlong *)0x0;
          if (plVar7 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0xcf;
            pcVar10 = (code *)FUN_23e91a870(param_1,plVar7);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            plVar8 = (longlong *)0x0;
            if (pcVar10 != (code *)0x0) goto LAB_23e24fb69;
          }
        }
      }
LAB_23e24fa80:
      lVar12 = *(longlong *)(param_1 + 0x60);
      uVar15 = *(undefined8 *)(param_1 + 0x68);
      uVar13 = *(undefined8 *)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e24f99d;
    }
    iVar4 = FUN_23e8be270(param_1,plVar2,_DAT_23eead758);
    if (iVar4 == -1) goto LAB_23e24f980;
    if (iVar4 != 0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eead758);
      plVar9 = (longlong *)0x0;
      if (plVar7 == (longlong *)0x0) goto LAB_23e24f9c0;
      iVar4 = FUN_23a35f020(plVar7);
      lVar11 = *plVar7 + -1;
      if (iVar4 == -1) {
        lVar12 = *(longlong *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = *(undefined8 *)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar7 = lVar11;
        if (lVar11 == 0) {
          plVar8 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        else {
          plVar8 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
        }
        goto LAB_23e24f99d;
      }
      *plVar7 = lVar11;
      if (lVar11 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (iVar4 != 1) goto LAB_23e24f753;
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eead758);
      plVar9 = (longlong *)0x0;
      if (plVar8 == (longlong *)0x0) goto LAB_23e24f9c0;
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eead740);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar9 == (longlong *)0x0) {
        lVar12 = *(longlong *)(param_1 + 0x60);
        uVar15 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = *(undefined8 *)(param_1 + 0x70);
        plVar9 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        goto LAB_23e24f99d;
      }
      *(undefined4 *)(plVar3 + 5) = 0xe7;
      pcVar10 = (code *)FUN_23e91a870(param_1,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plVar8 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      if (pcVar10 == (code *)0x0) goto LAB_23e24fa80;
      goto LAB_23e24fb69;
    }
LAB_23e24f753:
    plVar8 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar7 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar10 = _Py_NoneStruct_exref;
  plVar3[0xf] = 0;
  *(longlong *)pcVar10 = *(longlong *)pcVar10 + 1;
LAB_23e24f7b6:
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  return pcVar10;
}
