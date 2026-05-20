/* ===== 23e75b480 workers.fishing.fishing_bot:FishingBot._do_fish_catch ===== */
/* ghidra_name=FUN_23e75b480 entry=23e75b480 size=3111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e75b480(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  longlong *plVar15;
  undefined4 uStack_60;
  longlong *plStack_58;
  longlong *plStack_50;
  
  plVar8 = _DAT_23eedadd0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedadd0 == (longlong *)0x0) {
LAB_23e75b4ba:
    _DAT_23eedadd0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf40,DAT_23eedaeb8,0x18);
  }
  else {
    lVar2 = *_DAT_23eedadd0;
    if (1 < lVar2) {
      *_DAT_23eedadd0 = lVar2 + -1;
      goto LAB_23e75b4ba;
    }
    if (_DAT_23eedadd0[2] != 0) {
      *_DAT_23eedadd0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e75b4ba;
    }
  }
  plVar4 = _DAT_23eedadd0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedadd0 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eedadd0[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = DAT_23eed89b0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar8 == (longlong *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x70);
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    uStack_60 = 0x3ab;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e75b793;
  }
  *(undefined4 *)(plVar4 + 5) = 0x3ab;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed8d38);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar9 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar10 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uStack_60 = 0x3ab;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e75b793;
  }
  iVar7 = FUN_23a35f020(plVar9);
  lVar2 = *plVar9 + -1;
  if (iVar7 == -1) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = lVar2;
    if (lVar2 == 0) {
      plVar10 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uStack_60 = 0x3ab;
    }
    else {
      uStack_60 = 0x3ab;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
    }
    goto LAB_23e75b793;
  }
  *plVar9 = lVar2;
  if (lVar2 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar7 != 0) {
LAB_23e75b5bb:
    pcVar12 = _Py_NoneStruct_exref;
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar8 = *(longlong **)(lVar2 + 0x28);
    plVar4 = (longlong *)plVar8[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
    if (plVar4 != (longlong *)0x0) {
      plVar8[2] = 0;
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))();
      }
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8[0xf] = 0;
    goto LAB_23e75b61c;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89e0);
  if (plVar9 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uStack_60 = 0x3af;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e75b793;
  }
  iVar7 = FUN_23a35f020(plVar9);
  lVar2 = *plVar9 + -1;
  if (iVar7 == -1) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = lVar2;
    if (lVar2 == 0) {
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uStack_60 = 0x3af;
    }
    else {
      uStack_60 = 0x3af;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
    }
    goto LAB_23e75b793;
  }
  *plVar9 = lVar2;
  if (lVar2 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (iVar7 != 0) {
    cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89e0,_Py_FalseStruct_exref);
    if (cVar6 == '\0') {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar11 = (longlong *)0x0;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uStack_60 = 0x3b0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e75b793;
    }
    *(undefined4 *)(plVar4 + 5) = 0x3b1;
    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed92e8);
    if (plVar8 == (longlong *)0x0) {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      plVar11 = (longlong *)0x0;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uStack_60 = 0x3b1;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar10 = (longlong *)0x0;
      goto LAB_23e75b793;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    goto LAB_23e75b5bb;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89c0);
  if (plVar10 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uStack_60 = 0x3b5;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e75b793;
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89c8);
  if (plVar11 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar14 = *(undefined8 *)(param_1 + 0x68);
    uStack_60 = 0x3b6;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e75b793;
  }
  iVar7 = FUN_23a35f020(plVar10);
  if (iVar7 != -1) {
    if (iVar7 != 0) {
LAB_23e75ba1f:
      pcVar12 = _Py_FalseStruct_exref;
      cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89c0,_Py_FalseStruct_exref);
      if (cVar6 == '\0') {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uStack_60 = 0x3ba;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e75b793;
      }
      cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89c8,pcVar12);
      if (cVar6 == '\0') {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uStack_60 = 0x3bb;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e75b793;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed92f0);
      if (plVar8 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x3be;
        plStack_58 = plVar10;
        plStack_50 = plVar11;
        plVar9 = (longlong *)FUN_23e9186b0(param_1,plVar8,&plStack_58,_DAT_23eed92f8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          goto LAB_23e75bad0;
        }
      }
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar14 = *(undefined8 *)(param_1 + 0x68);
      uStack_60 = 0x3be;
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e75b793;
    }
    iVar7 = FUN_23a35f020(plVar11);
    if (iVar7 != -1) {
      if (iVar7 == 1) goto LAB_23e75ba1f;
LAB_23e75bad0:
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89d0);
      if (plVar9 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar14 = *(undefined8 *)(param_1 + 0x68);
        uStack_60 = 0x3c0;
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      else {
        iVar7 = FUN_23a35f020(plVar9);
        lVar2 = *plVar9 + -1;
        if (iVar7 == -1) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar14 = *(undefined8 *)(param_1 + 0x68);
          uStack_60 = 0x3c0;
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar9 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
            uStack_60 = 0x3c0;
          }
        }
        else {
          *plVar9 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          if (iVar7 != 0) {
            cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89d0,_Py_FalseStruct_exref);
            if (cVar6 == '\0') {
              uVar13 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = *(undefined8 *)(param_1 + 0x68);
              uStack_60 = 0x3c1;
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              goto LAB_23e75b793;
            }
            *(undefined4 *)(plVar4 + 5) = 0x3c2;
            plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed9300);
            if (plVar8 == (longlong *)0x0) {
              uVar13 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uStack_60 = 0x3c2;
              *(undefined8 *)(param_1 + 0x70) = 0;
              goto LAB_23e75b793;
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))();
            }
            lVar2 = DAT_23eed9090;
            *(undefined4 *)(plVar4 + 5) = 0x3c3;
            plVar8 = (longlong *)
                     FUN_23e915840(param_1,plVar1,DAT_23eed8c50,*(undefined8 *)(lVar2 + 0x18));
            if (plVar8 == (longlong *)0x0) {
              uVar13 = *(undefined8 *)(param_1 + 0x60);
              uVar14 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_60 = 0x3c3;
              goto LAB_23e75b793;
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89d8);
          if (plVar9 == (longlong *)0x0) {
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar14 = *(undefined8 *)(param_1 + 0x68);
            uStack_60 = 0x3c5;
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
          }
          else {
            iVar7 = FUN_23a35f020(plVar9);
            lVar2 = *plVar9 + -1;
            if (iVar7 != -1) {
              *plVar9 = lVar2;
              if (lVar2 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (iVar7 != 0) {
                cVar6 = FUN_23e8d9ac0(plVar1,DAT_23eed89d8,_Py_FalseStruct_exref);
                if (cVar6 == '\0') {
                  uVar13 = *(undefined8 *)(param_1 + 0x60);
                  uVar14 = *(undefined8 *)(param_1 + 0x68);
                  uStack_60 = 0x3c6;
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  goto LAB_23e75b793;
                }
                *(undefined4 *)(plVar4 + 5) = 0x3c7;
                plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23eed8e80);
                if (plVar8 == (longlong *)0x0) {
                  uVar13 = *(undefined8 *)(param_1 + 0x60);
                  uVar14 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uStack_60 = 0x3c7;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  goto LAB_23e75b793;
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
              }
              lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar8 = *(longlong **)(lVar2 + 0x28);
              plVar4 = (longlong *)plVar8[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
              *(undefined4 *)(plVar8 + 8) = 0xffffffff;
              if (plVar4 != (longlong *)0x0) {
                plVar8[2] = 0;
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              pcVar12 = _Py_NoneStruct_exref;
              plVar8[0xf] = 0;
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
LAB_23e75b61c:
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pcVar12;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pcVar12;
            }
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar14 = *(undefined8 *)(param_1 + 0x68);
            uStack_60 = 0x3c5;
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar9 = lVar2;
            if (lVar2 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
              uStack_60 = 0x3c5;
            }
          }
        }
      }
      goto LAB_23e75b793;
    }
  }
  uVar13 = *(undefined8 *)(param_1 + 0x60);
  uVar14 = *(undefined8 *)(param_1 + 0x68);
  uStack_60 = 0x3b8;
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e75b793:
  plVar9 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar12 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar12 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uStack_60;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar2;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar9 + -2;
    plVar15 = plVar9;
  }
  else {
    plVar15 = plVar8;
    if ((longlong *)plVar8[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar9[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar9 + 0x24) = uStack_60;
      pcVar12 = _PyRuntime_exref;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar9[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar9 + -2;
      plVar9[-2] = lVar2;
      plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar8;
      *(longlong **)(lVar2 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar8;
      plVar15 = plVar9;
      if (lVar3 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5dead,plVar1,plVar10,plVar11);
  if (_DAT_23eedadd0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedadd0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar13,uVar14,plVar15);
  return (code *)0x0;
}
