/* ===== 23e80c310 workers.fishing.memory_reeling:MemoryReelingTracker._u64 ===== */
/* ghidra_name=FUN_23e80c310 entry=23e80c310 size=1414 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e80c310(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar8 = _DAT_23eede8c8;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede8c8 == (longlong *)0x0) {
LAB_23e80c34e:
    _DAT_23eede8c8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9a8,DAT_23eedd0f8,0x18);
  }
  else {
    lVar10 = *_DAT_23eede8c8;
    if (1 < lVar10) {
      *_DAT_23eede8c8 = lVar10 + -1;
      goto LAB_23e80c34e;
    }
    if (_DAT_23eede8c8[2] != 0) {
      *_DAT_23eede8c8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e80c34e;
    }
  }
  plVar4 = _DAT_23eede8c8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eede8c8 + 9;
  lVar3 = *(longlong *)(lVar10 + 8);
  _DAT_23eede8c8[0xf] = lVar3;
  *(longlong **)(lVar10 + 8) = plVar8;
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
  plStack_60 = _DAT_23eedd3a0;
  *(undefined4 *)(plVar4 + 8) = 0;
  uVar6 = DAT_23eedd378;
  *(undefined4 *)(plVar4 + 5) = 0x119;
  plStack_68 = plVar2;
  plVar8 = (longlong *)FUN_23e954670(param_1,plVar1,uVar6,&plStack_68);
  if (plVar8 == (longlong *)0x0) {
    plVar9 = *(longlong **)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x68);
    uVar13 = 0x119;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e80c5e1;
  }
  plVar9 = (longlong *)FUN_23e8bd600(param_1,plVar8);
  if (plVar9 != (longlong *)0x0) {
    lVar10 = *plVar9 + -1;
    if (plVar9[2] == 1) {
      *plVar9 = lVar10;
      if ((int)plVar9[3] == 4) {
        if (lVar10 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
        lVar10 = FUN_23e8dc840();
        plVar9 = _DAT_23eedd3b8;
        if (lVar10 == 0) {
          FUN_23e915740(param_1,&plStack_68,_DAT_23eedd388);
          uVar13 = 0x11a;
          plVar9 = plStack_68;
          plVar11 = plStack_60;
          plVar14 = plStack_58;
          goto LAB_23e80c5e1;
        }
        *(undefined4 *)(plVar4 + 5) = 0x11a;
        plStack_68 = plVar9;
        plStack_60 = plVar8;
        plVar9 = (longlong *)FUN_23e954670(param_1,lVar10,_DAT_23eedd390,&plStack_68);
        if (plVar9 != (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23a388650(param_1,plVar9,DAT_23ed6ccf0,0);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar11 != (longlong *)0x0) goto LAB_23e80c457;
        }
        goto LAB_23e80c5c0;
      }
    }
    else {
      *plVar9 = lVar10;
    }
    if (lVar10 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    plVar11 = DAT_23ed6ccf0;
    *DAT_23ed6ccf0 = *DAT_23ed6ccf0 + 1;
LAB_23e80c457:
    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar4 = *(longlong **)(lVar10 + 0x28);
    plVar9 = (longlong *)plVar4[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
    *(undefined4 *)(plVar4 + 8) = 0xffffffff;
    if (plVar9 != (longlong *)0x0) {
      plVar4[2] = 0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))();
      }
    }
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    plVar4[0xf] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
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
    return plVar11;
  }
LAB_23e80c5c0:
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar13 = 0x11a;
  plVar9 = *(longlong **)(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = *(longlong **)(param_1 + 0x68);
LAB_23e80c5e1:
  plVar12 = DAT_23ed6a4f8;
  if (plVar14 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar10 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar3 = plVar12[-1];
    puVar5 = *(undefined8 **)(lVar10 + 8);
    *puVar5 = plVar12 + -2;
    plVar12[-2] = lVar10;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar10 + 8) = plVar12 + -2;
    plVar15 = plVar12;
  }
  else {
    plVar15 = plVar14;
    if ((longlong *)plVar14[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
      pcVar7 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar7 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar12[-1];
      puVar5 = *(undefined8 **)(lVar10 + 8);
      *puVar5 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar14;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar14;
      plVar15 = plVar12;
      if (lVar3 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e2be,plVar1,plVar2,plVar8);
  if (_DAT_23eede8c8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede8c8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar10 + 0x28);
  plVar14 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
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
  FUN_23a33aa70(param_1,plVar9,plVar11,plVar15);
  return (longlong *)0x0;
}
