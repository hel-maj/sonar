/* ===== 23aaab8b0 __main__:249 ===== */
/* ghidra_name=FUN_23aaab8b0 entry=23aaab8b0 size=2761 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aaab8b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong *plVar14;
  undefined4 uStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar8 = _DAT_23ed90c58;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23ed90c58 == (longlong *)0x0) {
LAB_23aaab8ee:
    _DAT_23ed90c58 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ed90c50,DAT_23ed90d18,0x18);
  }
  else {
    lVar3 = *_DAT_23ed90c58;
    if (1 < lVar3) {
      *_DAT_23ed90c58 = lVar3 + -1;
      goto LAB_23aaab8ee;
    }
    if (_DAT_23ed90c58[2] != 0) {
      *_DAT_23ed90c58 = lVar3 + -1;
      if (lVar3 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23aaab8ee;
    }
  }
  plVar4 = _DAT_23ed90c58;
  lVar3 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23ed90c58 + 9;
  lVar10 = *(longlong *)(lVar3 + 8);
  _DAT_23ed90c58[0xf] = lVar10;
  *(longlong **)(lVar3 + 8) = plVar8;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = DAT_23ed8fd88;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar8 == (longlong *)0x0) {
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_70 = 0xfc;
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    goto LAB_23aaabdf0;
  }
  iVar7 = FUN_23a35f020(plVar8);
  lVar3 = *plVar8 + -1;
  if (iVar7 == -1) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar8 = lVar3;
    if (lVar3 == 0) {
      plVar9 = (longlong *)0x0;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      uStack_70 = 0xfc;
    }
    else {
      uStack_70 = 0xfc;
      plVar9 = (longlong *)0x0;
    }
    goto LAB_23aaabdf0;
  }
  *plVar8 = lVar3;
  if (lVar3 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (iVar7 != 0) {
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
    if (plVar8 == (longlong *)0x0) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      uStack_70 = 0xfd;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = (longlong *)0x0;
      goto LAB_23aaabdf0;
    }
    *(undefined4 *)(plVar4 + 5) = 0xfd;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23ed8feb0);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar12 == (longlong *)0x0) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      plVar9 = (longlong *)0x0;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uStack_70 = 0xfd;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23aaabdf0;
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fda8);
  if (plVar8 == (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    plVar9 = (longlong *)0x0;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uStack_70 = 0x100;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23aaabdf0;
  }
  *(undefined4 *)(plVar4 + 5) = 0x100;
  plStack_68 = plVar2;
  plVar9 = (longlong *)FUN_23e9186b0(param_1,plVar8,&plStack_68,_DAT_23ed8feb8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if (plVar9 == (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uStack_70 = 0x100;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23aaabdf0;
  }
  iVar7 = FUN_23a35f020(plVar9);
  if (iVar7 == -1) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uStack_70 = 0x102;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23aaabdf0;
  }
  if (iVar7 == 0) {
    lVar10 = FUN_23ebc0cf0();
    lVar3 = _DAT_23ed8fee0;
    if (lVar10 == 0) {
      FUN_23e915740(param_1,&plStack_68,DAT_23ed8fba8);
      uStack_70 = 0x10c;
      plVar12 = plStack_68;
      uVar13 = uStack_60;
      plVar14 = plStack_58;
      goto LAB_23aaabdf0;
    }
    *(undefined4 *)(plVar4 + 5) = 0x10c;
    plVar8 = (longlong *)FUN_23e915840(param_1,lVar10,DAT_23ed8fbb0,*(undefined8 *)(lVar3 + 0x18));
    if (plVar8 == (longlong *)0x0) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      uStack_70 = 0x10c;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23aaabdf0;
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fc98);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x10d;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23ed8fee8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar12 != (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        goto LAB_23aaabd1c;
      }
    }
    plVar12 = *(longlong **)(param_1 + 0x60);
    uStack_70 = 0x10d;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23aaabdf0;
  }
  lVar10 = FUN_23ebc0cf0();
  lVar3 = _DAT_23ed8fec0;
  if (lVar10 == 0) {
    FUN_23e915740(param_1,&plStack_68,DAT_23ed8fba8);
    uStack_70 = 0x104;
    plVar12 = plStack_68;
    uVar13 = uStack_60;
    plVar14 = plStack_58;
    goto LAB_23aaabdf0;
  }
  *(undefined4 *)(plVar4 + 5) = 0x104;
  plVar8 = (longlong *)FUN_23e915840(param_1,lVar10,DAT_23ed8fbb0,*(undefined8 *)(lVar3 + 0x18));
  if (plVar8 == (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uStack_70 = 0x104;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23aaabdf0;
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
  if (plVar8 == (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uStack_70 = 0x105;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23aaabdf0;
  }
  iVar7 = FUN_23a35f020(plVar8);
  lVar3 = *plVar8 + -1;
  if (iVar7 == -1) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uStack_70 = 0x105;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar8 = lVar3;
    if (lVar3 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
      uStack_70 = 0x105;
    }
    goto LAB_23aaabdf0;
  }
  *plVar8 = lVar3;
  if (lVar3 == 0) {
    (**(code **)(plVar8[1] + 0x30))();
  }
  if (iVar7 == 0) {
LAB_23aaabacf:
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd58);
    if (plVar8 != (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23ed8fed0);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar11 != (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ed8fed8);
        if (plVar8 == (longlong *)0x0) {
          plVar12 = *(longlong **)(param_1 + 0x60);
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          uStack_70 = 0x109;
          plVar14 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            uStack_70 = 0x109;
          }
          goto LAB_23aaabdf0;
        }
        *(undefined4 *)(plVar4 + 5) = 0x109;
        plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar8);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar12 != (longlong *)0x0) {
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
LAB_23aaabd1c:
          lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar8 = *(longlong **)(lVar3 + 0x28);
          plVar4 = (longlong *)plVar8[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
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
          pcVar6 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar6;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar6;
        }
      }
    }
    plVar12 = *(longlong **)(param_1 + 0x60);
    uStack_70 = 0x109;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
  }
  else {
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed8fd88);
    if (plVar8 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0x106;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23ed8fec8);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar12 != (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        goto LAB_23aaabacf;
      }
    }
    plVar12 = *(longlong **)(param_1 + 0x60);
    uStack_70 = 0x106;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
  }
LAB_23aaabdf0:
  plVar8 = DAT_23ed6a4f8;
  if (plVar14 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar3 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uStack_70;
    lVar3 = *(longlong *)(lVar3 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar3 = *(longlong *)(lVar3 + 0x2e8);
    lVar10 = plVar8[-1];
    puVar5 = *(undefined8 **)(lVar3 + 8);
    *puVar5 = plVar8 + -2;
    plVar8[-2] = lVar3;
    plVar8[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar3 + 8) = plVar8 + -2;
    plVar11 = plVar8;
  }
  else {
    plVar11 = plVar14;
    if ((longlong *)plVar14[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uStack_70;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar10 = plVar8[-1];
      puVar5 = *(undefined8 **)(lVar3 + 8);
      *puVar5 = plVar8 + -2;
      plVar8[-2] = lVar3;
      plVar8[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar5;
      lVar10 = *plVar14;
      *(longlong **)(lVar3 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar14;
      plVar11 = plVar8;
      if (lVar10 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec31911,plVar1,plVar2,plVar9);
  if (_DAT_23ed90c58 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23ed90c58 = (longlong *)0x0;
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar3 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
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
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar12,uVar13,plVar11);
  return (code *)0x0;
}
