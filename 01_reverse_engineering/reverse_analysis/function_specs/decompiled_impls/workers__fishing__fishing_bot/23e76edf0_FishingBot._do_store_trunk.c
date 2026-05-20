/* ===== 23e76edf0 workers.fishing.fishing_bot:FishingBot._do_store_trunk ===== */
/* ghidra_name=FUN_23e76edf0 entry=23e76edf0 size=13871 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e76edf0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  code *pcVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  undefined4 uVar20;
  longlong *plVar21;
  undefined8 uVar22;
  code *pcVar23;
  code *pcVar24;
  undefined1 auVar25 [8];
  longlong *plStack_e0;
  int iStack_d8;
  longlong *plStack_d0;
  longlong *plStack_b0;
  code *pcStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined1 auStack_78 [8];
  longlong *plStack_70;
  longlong *aplStack_68 [5];
  
  plVar9 = _DAT_23eedad88;
  plVar1 = (longlong *)*param_3;
  aplStack_68[0] = (longlong *)0x0;
  auStack_78 = (undefined1  [8])0x0;
  plStack_70 = (longlong *)0x0;
  if (_DAT_23eedad88 == (longlong *)0x0) {
LAB_23e76ee4d:
    _DAT_23eedad88 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf88,DAT_23eedaeb8);
  }
  else {
    lVar11 = *_DAT_23eedad88;
    if (1 < lVar11) {
      *_DAT_23eedad88 = lVar11 + -1;
      goto LAB_23e76ee4d;
    }
    if (_DAT_23eedad88[2] != 0) {
      *_DAT_23eedad88 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e76ee4d;
    }
  }
  plVar21 = _DAT_23eedad88;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedad88 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23eedad88[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar21[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar21[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar21 = *plVar21 + 1;
  uVar22 = DAT_23eed89b0;
  *(undefined4 *)(plVar21 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar22);
  if (plVar9 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (aplStack_68[0] != (longlong *)0x0) {
      if ((longlong *)aplStack_68[0][3] != plVar21) {
        plVar12 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        uVar20 = 0x525;
        plVar9 = (longlong *)0x0;
        pcVar23 = _PyRuntime_exref;
        goto LAB_23e76fcd0;
      }
LAB_23e76ff90:
      plStack_e0 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      plVar14 = aplStack_68[0];
      goto LAB_23e76fd80;
    }
LAB_23e770110:
    plStack_e0 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    pcVar13 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    uVar20 = 0x525;
    pcVar23 = _PyRuntime_exref;
    goto LAB_23e770132;
  }
  *(undefined4 *)(plVar21 + 5) = 0x525;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8d38);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
    plStack_70 = *(longlong **)(param_1 + 0x68);
    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770110;
    if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e76ff90;
    plVar12 = (longlong *)0x0;
    pcVar15 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar20 = 0x525;
    pcVar13 = (code *)0x0;
    pcVar23 = _PyRuntime_exref;
LAB_23e76fcd0:
    plVar19 = aplStack_68[0];
    plVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar18 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar14[3] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    lVar11 = *(longlong *)(pcVar23 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar20;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar11;
    plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar14 + -2;
    plVar14[2] = (longlong)plVar19;
    *plVar19 = *plVar19 + 1;
    plVar19 = aplStack_68[0];
  }
  else {
    iVar8 = FUN_23a35f020(plVar10);
    lVar11 = *plVar10 + -1;
    if (iVar8 == -1) {
      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
      plStack_70 = *(longlong **)(param_1 + 0x68);
      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = lVar11;
      if (lVar11 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770110;
      if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e76ff90;
      plStack_e0 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      uVar20 = 0x525;
      pcVar23 = _PyRuntime_exref;
      goto LAB_23e76fcd0;
    }
    *plVar10 = lVar11;
    if (lVar11 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (iVar8 != 0) {
      plVar12 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      lVar11 = *(longlong *)_Py_NoneStruct_exref + 1;
      pcVar24 = _Py_NoneStruct_exref;
      goto LAB_23e76ef6b;
    }
    lVar11 = *(longlong *)(DAT_23eed8950 + 0x20);
    if (*(char *)(lVar11 + 10) == '\0') {
      plVar9 = (longlong *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9530);
      if (plVar9 == (longlong *)0x0) goto LAB_23e770000;
      lVar11 = *plVar9;
LAB_23e76ffec:
      if (lVar11 == 0) goto LAB_23e770000;
LAB_23e76f17d:
      *(undefined4 *)(plVar21 + 5) = 0x529;
      plVar9 = (longlong *)FUN_23e91a870(param_1);
      if (plVar9 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        aplStack_68[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (aplStack_68[0] != (longlong *)0x0) {
          if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e76ff90;
          plVar12 = (longlong *)0x0;
          pcVar15 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          uVar20 = 0x529;
          pcVar23 = _PyRuntime_exref;
          goto LAB_23e76fcd0;
        }
        goto LAB_23e7706b2;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      if (plVar10 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        aplStack_68[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (aplStack_68[0] == (longlong *)0x0) {
LAB_23e7705d0:
          plVar12 = (longlong *)0x0;
          pcVar15 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          uVar20 = 0x52c;
          pcVar23 = _PyRuntime_exref;
          goto LAB_23e770132;
        }
        if (plVar21 != (longlong *)aplStack_68[0][3]) {
          plVar12 = (longlong *)0x0;
          pcVar15 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          uVar20 = 0x52c;
          pcVar13 = (code *)0x0;
          pcVar23 = _PyRuntime_exref;
          goto LAB_23e76fcd0;
        }
LAB_23e770320:
        plVar12 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        plStack_e0 = (longlong *)0x0;
        plVar14 = aplStack_68[0];
        goto LAB_23e76fd80;
      }
      cVar7 = FUN_23e8d9ac0(plVar9,DAT_23eed8a98,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (cVar7 == '\0') {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        aplStack_68[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e7705d0;
        if ((longlong *)aplStack_68[0][3] != plVar21) {
          plVar12 = (longlong *)0x0;
          pcVar15 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          uVar20 = 0x52c;
          pcVar23 = _PyRuntime_exref;
          goto LAB_23e76fcd0;
        }
        goto LAB_23e770320;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
      if (plVar10 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
        plStack_70 = *(longlong **)(param_1 + 0x68);
        aplStack_68[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (aplStack_68[0] != (longlong *)0x0) {
          if (plVar21 != (longlong *)aplStack_68[0][3]) {
            plVar12 = (longlong *)0x0;
            pcVar15 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            uVar20 = 0x52d;
            pcVar13 = (code *)0x0;
            pcVar23 = _PyRuntime_exref;
            goto LAB_23e76fcd0;
          }
          goto LAB_23e770320;
        }
LAB_23e7706fe:
        plVar12 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        uVar20 = 0x52d;
        pcVar23 = _PyRuntime_exref;
      }
      else {
        iVar8 = FUN_23e913250(plVar10,DAT_23eed90d8);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (iVar8 == -1) {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (aplStack_68[0] != (longlong *)0x0) {
            plVar10 = (longlong *)aplStack_68[0][3];
joined_r0x00023e770313:
            if (plVar10 != plVar21) {
              plVar12 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              uVar20 = 0x52d;
              pcVar23 = _PyRuntime_exref;
              goto LAB_23e76fcd0;
            }
            goto LAB_23e770320;
          }
          goto LAB_23e7706fe;
        }
        uVar22 = DAT_23eed9220;
        if (iVar8 != 1) {
          uVar22 = DAT_23eed9388;
        }
        cVar7 = FUN_23e8d9ac0(plVar9,DAT_23eed9390,uVar22);
        if (cVar7 == '\0') {
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (aplStack_68[0] != (longlong *)0x0) {
            plVar10 = (longlong *)aplStack_68[0][3];
            goto joined_r0x00023e770313;
          }
          goto LAB_23e7706fe;
        }
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
        if (plVar10 == (longlong *)0x0) {
LAB_23e7701e0:
          pcVar13 = (code *)0x0;
          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
          plStack_70 = *(longlong **)(param_1 + 0x68);
          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (aplStack_68[0] != (longlong *)0x0) {
            if (plVar21 != (longlong *)aplStack_68[0][3]) {
              plVar12 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              uVar20 = 0x530;
              pcVar23 = _PyRuntime_exref;
              goto LAB_23e76fcd0;
            }
            goto LAB_23e770320;
          }
LAB_23e7706d9:
          plVar12 = (longlong *)0x0;
          pcVar15 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          pcVar13 = (code *)0x0;
          uVar20 = 0x530;
          pcVar23 = _PyRuntime_exref;
        }
        else {
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          pcVar15 = DAT_23eed8b60;
          lVar11 = DAT_23ed6cce8;
          if (plVar12 == (longlong *)0x0) {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            aplStack_68[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (aplStack_68[0] != (longlong *)0x0) {
              if ((longlong *)aplStack_68[0][3] != plVar21) {
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                pcVar13 = (code *)0x0;
                plStack_e0 = (longlong *)0x0;
                uVar20 = 0x530;
                plVar10 = (longlong *)0x0;
                pcVar23 = _PyRuntime_exref;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
            goto LAB_23e7706d9;
          }
          lVar2 = *(longlong *)(param_1 + 0x10);
          iVar8 = *(int *)(lVar2 + 0x1410);
          plVar10 = *(longlong **)(DAT_23ed6cce8 + 0x20);
          *plVar10 = *plVar10 + 1;
          if (iVar8 == 0) {
            plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
            plVar10 = *(longlong **)(lVar11 + 0x20);
          }
          else {
            iVar8 = iVar8 + -1;
            *(int *)(lVar2 + 0x1410) = iVar8;
            plVar14 = *(longlong **)(lVar2 + 0x1190 + (longlong)iVar8 * 8);
            *plVar14 = 1;
          }
          lVar11 = *(longlong *)(lVar11 + 0x28);
          plVar14[4] = (longlong)plVar10;
          plVar14[5] = lVar11;
          plVar14[2] = 0;
          plVar14[3] = 1;
          *(undefined4 *)(plVar21 + 5) = 0x530;
          pcStack_98 = pcVar15;
          plStack_90 = plVar14;
          plVar10 = (longlong *)FUN_23e94ed00(param_1,plVar12,&pcStack_98);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar10 == (longlong *)0x0) goto LAB_23e7701e0;
          cVar7 = FUN_23e8d9ac0(plVar9,DAT_23eed8b60,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (cVar7 == '\0') {
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            aplStack_68[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e7706d9;
            if (plVar21 != (longlong *)aplStack_68[0][3]) {
              plVar12 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              uVar20 = 0x530;
              pcVar23 = _PyRuntime_exref;
              goto LAB_23e76fcd0;
            }
            goto LAB_23e770320;
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8978);
          if (plVar10 == (longlong *)0x0) {
LAB_23e770653:
            pcVar13 = (code *)0x0;
            auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
            plStack_70 = *(longlong **)(param_1 + 0x68);
            aplStack_68[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (aplStack_68[0] != (longlong *)0x0) {
              if (plVar21 != (longlong *)aplStack_68[0][3]) {
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                uVar20 = 0x533;
                pcVar23 = _PyRuntime_exref;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
LAB_23e770893:
            plVar12 = (longlong *)0x0;
            pcVar15 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            pcVar13 = (code *)0x0;
            uVar20 = 0x533;
            pcVar23 = _PyRuntime_exref;
          }
          else {
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] != (longlong *)0x0) {
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  uVar20 = 0x533;
                  plVar10 = (longlong *)0x0;
                  pcVar23 = _PyRuntime_exref;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
              goto LAB_23e770893;
            }
            *(undefined4 *)(plVar21 + 5) = 0x533;
            plVar10 = (longlong *)FUN_23e9557e0(param_1,plVar12,_DAT_23eed9538);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar10 == (longlong *)0x0) goto LAB_23e770653;
            cVar7 = FUN_23e8d9ac0(plVar9,_DAT_23eed9540,plVar10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (cVar7 == '\0') {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770893;
              if (plVar21 != (longlong *)aplStack_68[0][3]) {
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                pcVar13 = (code *)0x0;
                uVar20 = 0x533;
                pcVar23 = _PyRuntime_exref;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
            plVar10 = _DAT_23eed9548;
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar23 = _PyRuntime_exref;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] != (longlong *)0x0) {
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  pcVar13 = (code *)0x0;
                  uVar20 = 0x536;
                  pcVar15 = (code *)0x0;
                  pcVar23 = _PyRuntime_exref;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
              goto LAB_23e770928;
            }
            lVar11 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar11 + 0xe20);
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar2 = plVar14[3];
              *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
              *(longlong *)(lVar11 + 0xe20) = lVar2;
              *plVar14 = 1;
            }
            pcVar23 = _PyRuntime_exref;
            plVar14[4] = 0;
            lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar14[-1];
            puVar3 = *(undefined8 **)(lVar11 + 8);
            *puVar3 = plVar14 + -2;
            plVar14[-2] = lVar11;
            plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
            *(longlong **)(lVar11 + 8) = plVar14 + -2;
            pcVar15 = DAT_23eed8b60;
            *plVar10 = *plVar10 + 1;
            plVar14[3] = (longlong)plVar10;
            pcVar13 = (code *)FUN_23e8bc2f0(plVar9,pcVar15);
            plVar10 = DAT_23ed6cd28;
            if (pcVar13 == (code *)0x0) {
LAB_23e770784:
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (aplStack_68[0] != (longlong *)0x0) {
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  plVar10 = (longlong *)0x0;
                  pcVar13 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  uVar20 = 0x536;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
LAB_23e770928:
              plVar12 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              plStack_e0 = (longlong *)0x0;
              uVar20 = 0x536;
              pcVar15 = (code *)0x0;
              goto LAB_23e770132;
            }
            pcVar15 = pcVar23;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar19 != (longlong *)0x0) {
                *plVar19 = *plVar19 + 1;
                DAT_23ed6a4c0 = plVar19;
                goto LAB_23e76f55e;
              }
LAB_23e770e28:
              pcVar23 = pcVar15;
              PyErr_PrintEx(0,0);
              Py_Exit(1);
LAB_23e770e3b:
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] == (longlong *)0x0) {
LAB_23e7721cc:
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                pcVar13 = (code *)0x0;
                uVar20 = 0x53a;
                goto LAB_23e770132;
              }
              if ((longlong *)aplStack_68[0][3] != plVar21) {
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                uVar20 = 0x53a;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
LAB_23e76f55e:
            plStack_90 = plVar10;
            pcStack_98 = pcVar13;
            lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
            *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
            if (*(longlong *)pcVar13 == 0) {
              (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
            }
            if (lVar11 == 0) goto LAB_23e770784;
            plVar14[4] = lVar11;
            plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar10 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
                if (aplStack_68[0] != (longlong *)0x0) {
                  plVar10 = (longlong *)aplStack_68[0][3];
joined_r0x00023e770bb1:
                  if (plVar10 != plVar21) {
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    plVar10 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    uVar20 = 0x536;
                    pcVar13 = (code *)0x0;
                    goto LAB_23e76fcd0;
                  }
                  goto LAB_23e770320;
                }
              }
              else if (aplStack_68[0] != (longlong *)0x0) {
                plVar10 = (longlong *)aplStack_68[0][3];
                goto joined_r0x00023e770bb1;
              }
              goto LAB_23e770928;
            }
            *(undefined4 *)(plVar21 + 5) = 0x536;
            plVar14 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))();
            }
            if (plVar14 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770928;
              if ((longlong *)aplStack_68[0][3] != plVar21) {
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                pcVar13 = (code *)0x0;
                plStack_e0 = (longlong *)0x0;
                uVar20 = 0x536;
                plVar10 = (longlong *)0x0;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
            plVar10 = _DAT_23eed9550;
            if (plVar12 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770b13;
              if ((longlong *)aplStack_68[0][3] != plVar21) {
                plVar12 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                pcVar13 = (code *)0x0;
                plStack_e0 = (longlong *)0x0;
                uVar20 = 0x537;
                pcVar15 = (code *)0x0;
                goto LAB_23e76fcd0;
              }
              goto LAB_23e770320;
            }
            lVar11 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar11 + 0xe20);
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar2 = plVar14[3];
              *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
              *(longlong *)(lVar11 + 0xe20) = lVar2;
              *plVar14 = 1;
            }
            lVar11 = *(longlong *)(pcVar23 + 0x1f8);
            plVar14[4] = 0;
            lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
            lVar2 = plVar14[-1];
            puVar3 = *(undefined8 **)(lVar11 + 8);
            *puVar3 = plVar14 + -2;
            plVar14[-2] = lVar11;
            plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
            *(longlong **)(lVar11 + 8) = plVar14 + -2;
            uVar22 = _DAT_23eed9540;
            *plVar10 = *plVar10 + 1;
            plVar14[3] = (longlong)plVar10;
            pcVar13 = (code *)FUN_23e8bc2f0(plVar9,uVar22);
            plVar10 = DAT_23ed6cd28;
            if (pcVar13 == (code *)0x0) {
LAB_23e770945:
              auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
              plStack_70 = *(longlong **)(param_1 + 0x68);
              aplStack_68[0] = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0();
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                FUN_23a334bc0();
              }
              if (aplStack_68[0] != (longlong *)0x0) {
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  plVar10 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  pcVar13 = (code *)0x0;
                  uVar20 = 0x537;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
LAB_23e770b13:
              plVar12 = (longlong *)0x0;
              pcVar15 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              uVar20 = 0x537;
            }
            else {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar19 == (longlong *)0x0) goto LAB_23e770e28;
                *plVar19 = *plVar19 + 1;
                DAT_23ed6a4c0 = plVar19;
              }
              plStack_90 = plVar10;
              pcStack_98 = pcVar13;
              lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
              *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
              if (*(longlong *)pcVar13 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
              }
              if (lVar11 == 0) goto LAB_23e770945;
              plVar14[4] = lVar11;
              plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                FUN_23a334bc0();
              }
              if (plVar10 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0();
                }
                if (aplStack_68[0] != (longlong *)0x0) {
                  if ((longlong *)aplStack_68[0][3] != plVar21) {
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    plVar10 = (longlong *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    uVar20 = 0x537;
                    pcVar13 = (code *)0x0;
                    goto LAB_23e76fcd0;
                  }
                  goto LAB_23e770320;
                }
                goto LAB_23e770b13;
              }
              *(undefined4 *)(plVar21 + 5) = 0x537;
              plVar14 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0();
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0();
              }
              if (plVar14 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e770b13;
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  uVar20 = 0x537;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                FUN_23a334bc0(plVar14);
              }
              plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8aa8);
              pcVar13 = (code *)0x0;
              if (plVar10 == (longlong *)0x0) goto LAB_23e770e3b;
              iVar8 = FUN_23e913250(plVar10,DAT_23eed90d8);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                FUN_23a334bc0(plVar10);
              }
              pcVar24 = _Py_NoneStruct_exref;
              uVar6 = _DAT_23eed9568;
              uVar5 = _DAT_23eed9560;
              uVar4 = _DAT_23eed9558;
              lVar11 = DAT_23eed8950;
              uVar22 = DAT_23ed6ccf0;
              if (iVar8 == -1) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e7721cc;
                if ((longlong *)aplStack_68[0][3] != plVar21) {
                  plVar12 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  uVar20 = 0x53a;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e76fcd0;
                }
                goto LAB_23e770320;
              }
              if (iVar8 == 1) {
                *(undefined4 *)(plVar21 + 5) = 0x53b;
                plVar10 = (longlong *)FUN_23e95c160(param_1,uVar4,lVar11,pcVar24,uVar5,uVar22);
                if (plVar10 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (aplStack_68[0] != (longlong *)0x0) {
                    if ((longlong *)aplStack_68[0][3] != plVar21) {
                      plVar12 = (longlong *)0x0;
                      pcVar15 = (code *)0x0;
                      pcVar13 = (code *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      uVar20 = 0x53b;
                      plVar10 = (longlong *)0x0;
                      goto LAB_23e76fcd0;
                    }
                    goto LAB_23e770320;
                  }
                }
                else {
                  if (((code *)plVar10[1] == PyModule_Type_exref) ||
                     (iVar8 = PyType_IsSubtype(), iVar8 != 0)) {
                    pcVar13 = (code *)FUN_23e970d20(param_1,plVar10,DAT_23eed8950,_DAT_23eed93a8,
                                                    DAT_23ed6ccf0);
                  }
                  else {
                    pcVar13 = (code *)FUN_23e8d2f70(param_1,plVar10,_DAT_23eed93a8);
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    FUN_23a334bc0(plVar10);
                  }
                  if (pcVar13 != (code *)0x0) {
                    cVar7 = FUN_23e8d9ac0(plVar9,_DAT_23eed93c0,pcVar13);
                    if (cVar7 == '\0') {
                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_70 = *(longlong **)(param_1 + 0x68);
                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (aplStack_68[0] != (longlong *)0x0) {
                        if ((longlong *)aplStack_68[0][3] == plVar21) {
LAB_23e77239d:
                          plVar12 = (longlong *)0x0;
                          pcVar15 = (code *)0x0;
                          plVar10 = (longlong *)0x0;
                          plStack_e0 = (longlong *)0x0;
                          plVar14 = aplStack_68[0];
                          goto LAB_23e76fd80;
                        }
                        pcVar15 = (code *)0x0;
                        plVar10 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        uVar20 = 0x53c;
                        plVar12 = (longlong *)0x0;
                        goto LAB_23e76fcd0;
                      }
                      plVar12 = (longlong *)0x0;
                      pcVar15 = (code *)0x0;
                      uVar20 = 0x53c;
                      plStack_e0 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                    }
                    else {
                      cVar7 = FUN_23e8d9ac0(plVar9,_DAT_23eed93d8,DAT_23eed90d8);
                      plVar10 = (longlong *)0x0;
                      if (cVar7 != '\0') goto LAB_23e76fa18;
                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_70 = *(longlong **)(param_1 + 0x68);
                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (aplStack_68[0] != (longlong *)0x0) {
                        if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e77239d;
                        plVar12 = (longlong *)0x0;
                        pcVar15 = (code *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        uVar20 = 0x53d;
                        goto LAB_23e76fcd0;
                      }
                      pcVar15 = (code *)0x0;
                      uVar20 = 0x53d;
                      plStack_e0 = (longlong *)0x0;
                      plVar12 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                    }
                    goto LAB_23e770132;
                  }
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (aplStack_68[0] != (longlong *)0x0) {
                    if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e770320;
                    plVar12 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar20 = 0x53b;
                    plStack_e0 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    goto LAB_23e76fcd0;
                  }
                }
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                pcVar13 = (code *)0x0;
                uVar20 = 0x53b;
                goto LAB_23e770132;
              }
              *(undefined4 *)(plVar21 + 5) = 0x53f;
              plVar12 = (longlong *)FUN_23e95c160(param_1,uVar4,lVar11,pcVar24,uVar6,uVar22);
              if (plVar12 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                plStack_70 = *(longlong **)(param_1 + 0x68);
                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (aplStack_68[0] != (longlong *)0x0) {
                  if ((longlong *)aplStack_68[0][3] != plVar21) {
                    pcVar15 = (code *)0x0;
                    plVar10 = (longlong *)0x0;
                    uVar20 = 0x53f;
                    plStack_e0 = (longlong *)0x0;
                    plVar12 = (longlong *)0x0;
                    pcVar13 = (code *)0x0;
                    goto LAB_23e76fcd0;
                  }
                  goto LAB_23e770320;
                }
LAB_23e77228b:
                plVar12 = (longlong *)0x0;
                pcVar15 = (code *)0x0;
                plVar10 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                pcVar13 = (code *)0x0;
                uVar20 = 0x53f;
              }
              else {
                if (((code *)plVar12[1] == PyModule_Type_exref) ||
                   (iVar8 = PyType_IsSubtype(), iVar8 != 0)) {
                  plVar10 = (longlong *)
                            FUN_23e970d20(param_1,plVar12,DAT_23eed8950,_DAT_23eed93e8,DAT_23ed6ccf0
                                         );
                }
                else {
                  plVar10 = (longlong *)FUN_23e8d2f70(param_1,plVar12,_DAT_23eed93e8);
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0();
                }
                if (plVar10 == (longlong *)0x0) {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (aplStack_68[0] != (longlong *)0x0) {
                    if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e770320;
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    pcVar13 = (code *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    uVar20 = 0x53f;
                    goto LAB_23e76fcd0;
                  }
                  goto LAB_23e77228b;
                }
                cVar7 = FUN_23e8d9ac0(plVar9,_DAT_23eed93c0,plVar10);
                if (cVar7 == '\0') {
                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                  plStack_70 = *(longlong **)(param_1 + 0x68);
                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (aplStack_68[0] != (longlong *)0x0) {
                    if ((longlong *)aplStack_68[0][3] == plVar21) {
LAB_23e770f94:
                      plVar12 = (longlong *)0x0;
                      pcVar15 = (code *)0x0;
                      pcVar13 = (code *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      plVar14 = aplStack_68[0];
                      goto LAB_23e76fd80;
                    }
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    plStack_e0 = (longlong *)0x0;
                    pcVar13 = (code *)0x0;
                    uVar20 = 0x540;
                    goto LAB_23e76fcd0;
                  }
                  plVar12 = (longlong *)0x0;
                  uVar20 = 0x540;
                  plStack_e0 = (longlong *)0x0;
                  pcVar15 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                }
                else {
                  pcVar13 = (code *)0x0;
                  cVar7 = FUN_23e8d9ac0(plVar9,_DAT_23eed93d8,DAT_23ed6cd28);
                  if (cVar7 == '\0') {
                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                    plStack_70 = *(longlong **)(param_1 + 0x68);
                    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (aplStack_68[0] != (longlong *)0x0) {
                      if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e770f94;
                      plVar12 = (longlong *)0x0;
                      pcVar15 = (code *)0x0;
                      plStack_e0 = (longlong *)0x0;
                      pcVar13 = (code *)0x0;
                      uVar20 = 0x541;
                      goto LAB_23e76fcd0;
                    }
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    uVar20 = 0x541;
                    plStack_e0 = (longlong *)0x0;
                    pcVar13 = (code *)0x0;
                  }
                  else {
LAB_23e76fa18:
                    lVar11 = FUN_23e8dffd0();
                    if (lVar11 == 0) {
                      FUN_23e915740(param_1,auStack_78,DAT_23eed9400);
joined_r0x00023e7722dd:
                      pcVar15 = (code *)0x0;
                      if (aplStack_68[0] != (longlong *)0x0) {
                        if ((longlong *)aplStack_68[0][3] != plVar21) {
                          plVar12 = (longlong *)0x0;
                          uVar20 = 0x544;
                          plStack_e0 = (longlong *)0x0;
                          goto LAB_23e76fcd0;
                        }
LAB_23e771304:
                        plVar12 = (longlong *)0x0;
                        pcVar15 = (code *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plVar14 = aplStack_68[0];
                        goto LAB_23e76fd80;
                      }
                    }
                    else {
                      *(undefined4 *)(plVar21 + 5) = 0x544;
                      plVar12 = (longlong *)FUN_23e91a870(param_1,lVar11);
                      if (plVar12 != (longlong *)0x0) {
                        plVar14 = (longlong *)FUN_23e8c6f80(plVar12,_DAT_23eed9570);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        if (plVar14 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto joined_r0x00023e7722dd;
                        }
                        cVar7 = FUN_23e8d9ac0(plVar9,DAT_23eed9410,plVar14);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        if (cVar7 == '\0') {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e7722e3;
                          if ((longlong *)aplStack_68[0][3] != plVar21) {
                            plVar12 = (longlong *)0x0;
                            uVar20 = 0x544;
                            plStack_e0 = (longlong *)0x0;
                            pcVar15 = (code *)0x0;
                            goto LAB_23e76fcd0;
                          }
                          goto LAB_23e771304;
                        }
                        *(undefined4 *)(plVar21 + 5) = 0x547;
                        plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed9418);
                        if (plVar12 == (longlong *)0x0) {
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (aplStack_68[0] == (longlong *)0x0) {
LAB_23e77212f:
                            plVar12 = (longlong *)0x0;
                            uVar20 = 0x547;
                            plStack_e0 = (longlong *)0x0;
                            pcVar15 = (code *)0x0;
                            goto LAB_23e770132;
                          }
                          if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e771304;
                          plVar12 = (longlong *)0x0;
                          uVar20 = 0x547;
                          plStack_e0 = (longlong *)0x0;
                          pcVar15 = (code *)0x0;
                        }
                        else {
                          iVar8 = FUN_23a35f020(plVar12);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          lVar11 = _DAT_23eed9578;
                          uVar22 = DAT_23eed8b40;
                          if (iVar8 != -1) {
                            if (iVar8 == 0) {
                              *(undefined4 *)(plVar21 + 5) = 0x548;
                              plVar12 = (longlong *)
                                        FUN_23e915840(param_1,plVar1,uVar22,
                                                      *(undefined8 *)(lVar11 + 0x18));
                              if (plVar12 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                plStack_70 = *(longlong **)(param_1 + 0x68);
                                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (aplStack_68[0] == (longlong *)0x0) {
                                  uVar20 = 0x548;
                                  plStack_e0 = (longlong *)0x0;
                                  plVar12 = (longlong *)0x0;
                                  pcVar15 = (code *)0x0;
                                  goto LAB_23e770132;
                                }
                                if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e771304;
                                pcVar15 = (code *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                uVar20 = 0x548;
                                plVar12 = (longlong *)0x0;
                                goto LAB_23e76fcd0;
                              }
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                              }
                              plVar12 = (longlong *)0x0;
                              pcVar15 = (code *)0x0;
                              lVar11 = *(longlong *)pcVar24 + 1;
LAB_23e76ef6b:
                              *(longlong *)pcVar24 = lVar11;
                              lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                              plVar21 = *(longlong **)(lVar11 + 0x28);
                              plVar14 = (longlong *)plVar21[2];
                              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                   *(undefined8 *)(lVar11 + 0x30);
                              *(undefined4 *)(plVar21 + 8) = 0xffffffff;
                              if (plVar14 != (longlong *)0x0) {
                                plVar21[2] = 0;
                                *plVar14 = *plVar14 + -1;
                                if (*plVar14 == 0) {
                                  (**(code **)(plVar14[1] + 0x30))();
                                }
                              }
                              *plVar21 = *plVar21 + -1;
                              if (*plVar21 == 0) {
                                (**(code **)(plVar21[1] + 0x30))(plVar21);
                              }
                              plVar21[0xf] = 0;
                              plStack_e0 = (longlong *)0x0;
                              plVar21 = (longlong *)0x0;
                              if (plVar9 == (longlong *)0x0) goto LAB_23e76eff3;
                            }
                            else {
                              plVar12 = (longlong *)FUN_23e8bc2f0();
                              if (plVar12 == (longlong *)0x0) {
LAB_23e77240d:
                                auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                plStack_70 = *(longlong **)(param_1 + 0x68);
                                aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plVar12 = (longlong *)0x0;
                                uVar20 = 0x54d;
                                pcVar15 = (code *)0x0;
                                plStack_e0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7713fa:
                                plVar14 = aplStack_68[0];
                                plStack_90 = plStack_70;
                                pcStack_98 = (code *)auStack_78;
                                auStack_78 = (undefined1  [8])0x0;
                                plStack_70 = (longlong *)0x0;
                                plStack_88 = aplStack_68[0];
                                aplStack_68[0] = (longlong *)0x0;
                                plVar19 = *(longlong **)(param_1 + 0x138);
                                if (plVar19 != (longlong *)0x0) {
                                  *plVar19 = *plVar19 + 1;
                                }
                                if (plVar14 == (longlong *)0x0) {
                                  lVar11 = FUN_23e8d6280(plVar21,uVar20);
                                  if ((plStack_88 != (longlong *)0x0) &&
                                     (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
                                    FUN_23a334bc0();
                                  }
                                }
                                else {
                                  lVar11 = FUN_23e8d6280(plVar21,uVar20);
                                  *(longlong **)(lVar11 + 0x10) = plVar14;
                                  *plVar14 = *plVar14 + 1;
                                  if ((plStack_88 != (longlong *)0x0) &&
                                     (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
                                    FUN_23a334bc0();
                                  }
                                }
                                plStack_88 = (longlong *)lVar11;
                                FUN_23a35ef40(param_1,&pcStack_98);
                                iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                               (*(longlong *)(param_1 + 0x138) + 8),
                                                      *(undefined8 *)PyExc_Exception_exref);
                                if (iVar8 == 0) {
                                  cVar7 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138));
                                  plVar14 = aplStack_68[0];
                                  iStack_d8 = 0;
                                  if (cVar7 == '\0') {
                                    iStack_d8 = 0x54c;
                                  }
                                  if (aplStack_68[0] == (longlong *)0x0) {
                                    _auStack_78 = (undefined1  [16])0x0;
                                    FUN_23ebf6ae0(param_1,plVar19);
                                    aplStack_68[0] = (longlong *)0x0;
                                    uVar20 = 0x54c;
                                    if (iStack_d8 == 0) {
                                      uVar20 = (undefined4)plVar21[5];
                                    }
                                    goto LAB_23e770132;
                                  }
                                  if ((longlong *)aplStack_68[0][3] == plVar21) {
                                    *(undefined4 *)(plVar21 + 5) =
                                         *(undefined4 *)((longlong)aplStack_68[0] + 0x24);
                                  }
                                  aplStack_68[0] = (longlong *)0x0;
                                  _auStack_78 = (undefined1  [16])0x0;
                                  FUN_23ebf6ae0(param_1,plVar19);
                                  if ((longlong *)plVar14[3] == plVar21) goto LAB_23e76fd80;
                                  aplStack_68[0] = plVar14;
                                  if (iStack_d8 == 0) {
                                    uVar20 = (undefined4)plVar21[5];
                                  }
                                  else {
                                    uVar20 = 0x54c;
                                  }
                                  goto LAB_23e76fcd0;
                                }
                                plVar18 = *(longlong **)(param_1 + 0x138);
                                *plVar18 = *plVar18 + 1;
                                if (plVar1 == (longlong *)0x0) {
                                  FUN_23e8ba2b0(auStack_78,DAT_23eed8d30);
                                  if ((auStack_78 != (undefined1  [8])pcVar24) &&
                                     (auStack_78 != (undefined1  [8])0x0)) {
                                    FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,aplStack_68);
                                  }
                                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138));
                                }
                                else {
                                  plVar16 = (longlong *)FUN_23e8bc2f0();
                                  plVar14 = _DAT_23eed95a0;
                                  if (plVar16 == (longlong *)0x0) {
LAB_23e771928:
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar17 = (longlong *)
                                              FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                    *plVar14 = *plVar14 + 1;
                                    plVar17[3] = (longlong)plVar14;
                                    lVar11 = FUN_23e94f9d0(param_1,plVar18,DAT_23ed6cd28);
                                    if (lVar11 == 0) {
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0(plVar16);
                                      }
                                      lVar11 = *plVar17;
                                      *plVar17 = lVar11 + -1;
                                      if (lVar11 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                    else {
                                      plVar17[4] = lVar11;
                                      plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                                      lVar11 = *plVar17;
                                      *plVar17 = lVar11 + -1;
                                      if (lVar11 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar14 != (longlong *)0x0) {
                                        *(undefined4 *)(plVar21 + 5) = 0x55d;
                                        plVar17 = (longlong *)FUN_23e914090(param_1,plVar16);
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plVar17 != (longlong *)0x0) {
                                          *plVar17 = *plVar17 + -1;
                                          if (*plVar17 == 0) {
                                            FUN_23a334bc0(plVar17);
                                          }
                                          lVar11 = *plVar18;
                                          *plVar18 = lVar11 + -1;
                                          if (lVar11 + -1 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          FUN_23ebf6ae0(param_1,plVar19);
                                          goto LAB_23e77176c;
                                        }
                                        goto LAB_23e771928;
                                      }
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0(plVar16);
                                      }
                                    }
                                  }
                                }
                                plVar14 = aplStack_68[0];
                                plVar16 = plStack_70;
                                auVar25 = auStack_78;
                                _auStack_78 = (undefined1  [16])0x0;
                                lVar11 = *plVar18;
                                aplStack_68[0] = (longlong *)0x0;
                                *plVar18 = lVar11 + -1;
                                if (lVar11 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                aplStack_68[0] = (longlong *)0x0;
                                _auStack_78 = (undefined1  [16])0x0;
                                FUN_23ebf6ae0(param_1,plVar19);
                                aplStack_68[0] = plVar14;
                                auStack_78 = auVar25;
                                plStack_70 = plVar16;
                                if (plVar14 == (longlong *)0x0) {
                                  uVar20 = 0x55d;
                                  goto LAB_23e770132;
                                }
                                if (plVar21 == (longlong *)plVar14[3]) goto LAB_23e76fd80;
                                uVar20 = 0x55d;
                                goto LAB_23e76fcd0;
                              }
                              *(undefined4 *)(plVar21 + 5) = 0x54d;
                              pcVar15 = (code *)FUN_23e91bfe0(param_1,plVar12,DAT_23eed8a98);
                              *plVar12 = *plVar12 + -1;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0();
                              }
                              if (pcVar15 == (code *)0x0) goto LAB_23e77240d;
                              if (pcVar15 != pcVar24) {
                                *(undefined4 *)(plVar21 + 5) = 0x550;
                                plVar12 = (longlong *)FUN_23e915840(param_1,plVar9);
                                if (plVar12 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  plStack_70 = *(longlong **)(param_1 + 0x68);
                                  aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                  uVar20 = 0x550;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_e0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  iVar8 = FUN_23a35f020(plVar12);
                                  lVar11 = _DAT_23eed9588;
                                  uVar22 = DAT_23eed8b40;
                                  if (iVar8 == -1) {
                                    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                    uVar20 = 0x552;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_e0 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else if (iVar8 == 0) {
                                    *(undefined4 *)(plVar21 + 5) = 0x553;
                                    plVar14 = (longlong *)
                                              FUN_23e915840(param_1,plVar1,uVar22,
                                                            *(undefined8 *)(lVar11 + 0x18));
                                    if (plVar14 != (longlong *)0x0) {
                                      lVar11 = *plVar14;
                                      *plVar14 = lVar11 + -1;
                                      if (lVar11 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      lVar11 = *(longlong *)pcVar24 + 1;
                                      goto LAB_23e76ef6b;
                                    }
                                    aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                    auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    uVar20 = 0x553;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_e0 = (longlong *)0x0;
                                    plStack_70 = *(longlong **)(param_1 + 0x68);
                                  }
                                  else {
                                    plVar14 = (longlong *)FUN_23ebf7180(plVar12);
                                    if (plVar14 == (longlong *)0x0) {
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                      uVar20 = 0x556;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plStack_e0 = (longlong *)0x0;
                                    }
                                    else {
                                      plStack_b0 = (longlong *)0x0;
                                      do {
                                        plVar19 = (longlong *)FUN_23a388450(plVar14);
                                        if (plVar19 == (longlong *)0x0) {
                                          cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)
                                                                         PyExc_StopIteration_exref);
                                          if (cVar7 == '\0') {
                                            plStack_d0 = *(longlong **)(param_1 + 0x70);
                                            auVar25 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            plVar19 = *(longlong **)(param_1 + 0x68);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar20 = 0x556;
                                            aplStack_68[0] = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            _auStack_78 = (undefined1  [16])0x0;
                                            if (plStack_b0 != (longlong *)0x0) goto LAB_23e771bb2;
                                            goto LAB_23e771bf2;
                                          }
                                          plVar19 = plStack_b0;
                                          if (plStack_b0 != (longlong *)0x0) {
LAB_23e771c6a:
                                            *plVar19 = *plVar19 + -1;
                                            plStack_b0 = plVar19;
                                            if (*plVar19 == 0) {
                                              FUN_23a334bc0(plVar19);
                                            }
                                          }
                                          lVar11 = *plVar14;
                                          *plVar14 = lVar11 + -1;
                                          plStack_e0 = plStack_b0;
                                          if (lVar11 + -1 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          goto LAB_23e77176c;
                                        }
                                        if (plStack_b0 == (longlong *)0x0) {
                                          *plVar19 = *plVar19 + 1;
                                        }
                                        else {
                                          *plStack_b0 = *plStack_b0 + -1;
                                          if (*plStack_b0 == 0) {
                                            FUN_23a334bc0(plStack_b0);
                                          }
                                          *plVar19 = *plVar19 + 1;
                                          *plStack_b0 = *plStack_b0 + -1;
                                          if (*plStack_b0 == 0) {
                                            FUN_23a334bc0(plStack_b0);
                                          }
                                        }
                                        plStack_b0 = plVar19;
                                        if (plVar1 == (longlong *)0x0) {
                                          FUN_23e8ba2b0(auStack_78,DAT_23eed8d30);
                                          if ((auStack_78 != (undefined1  [8])pcVar24) &&
                                             (auStack_78 != (undefined1  [8])0x0)) {
                                            FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,
                                                          aplStack_68);
                                          }
                                          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),plStack_70)
                                          ;
LAB_23e771d82:
                                          uVar20 = 0x557;
                                          goto LAB_23e771b7e;
                                        }
                                        plVar18 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
                                        if (plVar18 == (longlong *)0x0) {
LAB_23e771d8c:
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          plStack_70 = *(longlong **)(param_1 + 0x68);
                                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e771d82;
                                        }
                                        *(undefined4 *)(plVar21 + 5) = 0x557;
                                        plVar16 = (longlong *)FUN_23e91bfe0(param_1,plVar18);
                                        *plVar18 = *plVar18 + -1;
                                        if (*plVar18 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plVar16 == (longlong *)0x0) goto LAB_23e771d8c;
                                        iVar8 = FUN_23a35f020(plVar16);
                                        lVar11 = *plVar16 + -1;
                                        if (iVar8 == -1) {
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          plStack_70 = *(longlong **)(param_1 + 0x68);
                                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar16 = lVar11;
                                          if (lVar11 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          goto LAB_23e771d82;
                                        }
                                        *plVar16 = lVar11;
                                        if (lVar11 == 0) {
                                          FUN_23a334bc0(plVar16);
                                        }
                                        if (iVar8 != 0) goto LAB_23e771c6a;
                                        *(undefined4 *)(plVar21 + 5) = 0x55a;
                                        plVar19 = (longlong *)FUN_23e915840(param_1,plVar9);
                                        if (plVar19 == (longlong *)0x0) {
                                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          plStack_70 = *(longlong **)(param_1 + 0x68);
                                          uVar20 = 0x55a;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e771b7e;
                                        }
                                        *plVar19 = *plVar19 + -1;
                                        if (*plVar19 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        cVar7 = FUN_23a3a5fe0();
                                      } while (cVar7 != '\0');
                                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      plStack_70 = *(longlong **)(param_1 + 0x68);
                                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                                      uVar20 = 0x556;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
LAB_23e771b7e:
                                      plStack_d0 = aplStack_68[0];
                                      auVar25 = auStack_78;
                                      plVar19 = plStack_70;
LAB_23e771bb2:
                                      aplStack_68[0] = (longlong *)0x0;
                                      _auStack_78 = (undefined1  [16])0x0;
                                      *plStack_b0 = *plStack_b0 + -1;
                                      if (*plStack_b0 == 0) {
                                        FUN_23a334bc0(plStack_b0);
                                      }
LAB_23e771bf2:
                                      lVar11 = *plVar14;
                                      *plVar14 = lVar11 + -1;
                                      if (lVar11 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      aplStack_68[0] = plStack_d0;
                                      plStack_e0 = plStack_b0;
                                      auStack_78 = auVar25;
                                      plStack_70 = plVar19;
                                    }
                                  }
                                }
                                goto LAB_23e7713fa;
                              }
                              plVar12 = (longlong *)0x0;
                              plStack_e0 = (longlong *)0x0;
LAB_23e77176c:
                              FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                              *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
                            }
                            *plVar9 = *plVar9 + -1;
                            plVar21 = plStack_e0;
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))(plVar9);
                            }
LAB_23e76eff3:
                            if ((pcVar13 != (code *)0x0) &&
                               (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1,
                               *(longlong *)pcVar13 == 0)) {
                              (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                            }
                            if ((plVar10 != (longlong *)0x0) &&
                               (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            if ((pcVar15 != (code *)0x0) &&
                               (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1,
                               *(longlong *)pcVar15 == 0)) {
                              (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                            }
                            if ((plVar12 != (longlong *)0x0) &&
                               (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            if ((plVar21 != (longlong *)0x0) &&
                               (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                              (**(code **)(plVar21[1] + 0x30))(plVar21);
                            }
                            *plVar1 = *plVar1 + -1;
                            if (*plVar1 != 0) {
                              return pcVar24;
                            }
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                            return pcVar24;
                          }
                          auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                          plStack_70 = *(longlong **)(param_1 + 0x68);
                          aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (aplStack_68[0] == (longlong *)0x0) goto LAB_23e77212f;
                          if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e771304;
                          plVar12 = (longlong *)0x0;
                          pcVar15 = (code *)0x0;
                          uVar20 = 0x547;
                          plStack_e0 = (longlong *)0x0;
                        }
                        goto LAB_23e76fcd0;
                      }
                      auStack_78 = *(undefined1 (*) [8])(param_1 + 0x60);
                      plStack_70 = *(longlong **)(param_1 + 0x68);
                      aplStack_68[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (aplStack_68[0] != (longlong *)0x0) {
                        if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e771304;
                        pcVar15 = (code *)0x0;
                        uVar20 = 0x544;
                        plStack_e0 = (longlong *)0x0;
                        plVar12 = (longlong *)0x0;
                        goto LAB_23e76fcd0;
                      }
                    }
LAB_23e7722e3:
                    plVar12 = (longlong *)0x0;
                    pcVar15 = (code *)0x0;
                    uVar20 = 0x544;
                    plStack_e0 = (longlong *)0x0;
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar8 = *(int *)(lVar11 + 0xc);
      if (*(int *)(lVar11 + 0xc) == 0) {
        *(int *)(lVar11 + 0xc) = DAT_23ec1545c;
        iVar8 = DAT_23ec1545c;
        DAT_23ec1545c = DAT_23ec1545c + 1;
      }
      if (_DAT_23ec15424 != iVar8) {
        _DAT_23ec15424 = iVar8;
        _DAT_23eedad80 = FUN_23e8cbd60(lVar11,_DAT_23eed9530,*(undefined8 *)(_DAT_23eed9530 + 0x18))
        ;
      }
      if (-1 < _DAT_23eedad80) {
        lVar2 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
        if (*(longlong *)(lVar2 + 8 + _DAT_23eedad80 * 0x10) != 0) goto LAB_23e76f17d;
        _DAT_23eedad80 = FUN_23e8cbd60(lVar11,_DAT_23eed9530,*(undefined8 *)(_DAT_23eed9530 + 0x18))
        ;
        if (-1 < _DAT_23eedad80) {
          lVar11 = *(longlong *)(lVar2 + 8 + _DAT_23eedad80 * 0x10);
          goto LAB_23e76ffec;
        }
      }
LAB_23e770000:
      plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9530);
      if ((plVar9 != (longlong *)0x0) && (*plVar9 != 0)) goto LAB_23e76f17d;
      FUN_23e915740(param_1,auStack_78,_DAT_23eed9530);
      if (aplStack_68[0] != (longlong *)0x0) {
        if ((longlong *)aplStack_68[0][3] == plVar21) goto LAB_23e76ff90;
        plStack_e0 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        pcVar13 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        pcVar15 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        uVar20 = 0x529;
        pcVar23 = _PyRuntime_exref;
        goto LAB_23e76fcd0;
      }
LAB_23e7706b2:
      plStack_e0 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      pcVar15 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      uVar20 = 0x529;
      pcVar23 = _PyRuntime_exref;
    }
LAB_23e770132:
    plVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      plVar19 = aplStack_68[0];
    }
    else {
      plVar19 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar19 = (longlong *)0x0;
    }
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    lVar11 = *(longlong *)(pcVar23 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar20;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar2 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar11 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar11;
    plVar14[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar11 + 8) = plVar14 + -2;
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))();
  }
LAB_23e76fd80:
  aplStack_68[0] = plVar14;
  FUN_23e8bba40(plVar21,"oooooooo",plVar1,plVar9,pcVar13,plVar10,pcVar15,plVar12,plStack_e0,0);
  if (_DAT_23eedad88 == plVar21) {
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))(plVar21);
    }
    _DAT_23eedad88 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar21 = *(longlong **)(lVar11 + 0x28);
  plVar14 = (longlong *)plVar21[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar21 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar21[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  plVar19 = aplStack_68[0];
  plVar14 = plStack_70;
  auVar25 = auStack_78;
  plVar21[0xf] = 0;
  _auStack_78 = (undefined1  [16])0x0;
  aplStack_68[0] = (longlong *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar11 = *plStack_e0, *plStack_e0 = lVar11 + -1, lVar11 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  *plVar1 = *plVar1 + -1;
  aplStack_68[0] = plVar19;
  auStack_78 = auVar25;
  plStack_70 = plVar14;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78,plStack_70,aplStack_68[0]);
  return (code *)0x0;
}
