/* ===== 23e7fea70 workers.fishing.memory_reeling:MemoryReelingTracker.__init__ ===== */
/* ghidra_name=FUN_23e7fea70 entry=23e7fea70 size=4713 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7fea70(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  longlong *plVar8;
  code *pcVar9;
  code *pcVar10;
  char cVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  longlong lStack_70;
  longlong *plStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar16 = _DAT_23eede940;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eede940 == (longlong *)0x0) {
LAB_23e7feab5:
    _DAT_23eede940 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede9f8,DAT_23eedd0f8,0x18);
  }
  else {
    lVar12 = *_DAT_23eede940;
    if (1 < lVar12) {
      *_DAT_23eede940 = lVar12 + -1;
      goto LAB_23e7feab5;
    }
    if (_DAT_23eede940[2] != 0) {
      *_DAT_23eede940 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      goto LAB_23e7feab5;
    }
  }
  plVar6 = _DAT_23eede940;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar16 = _DAT_23eede940 + 9;
  lVar4 = *(longlong *)(lVar12 + 8);
  _DAT_23eede940[0xf] = lVar4;
  *(longlong **)(lVar12 + 8) = plVar16;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar16 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar16;
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar7 = DAT_23eedd120;
  *(undefined4 *)(plVar6 + 8) = 0;
  cVar11 = FUN_23e8d9ac0(plVar1,uVar7,plVar2);
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = DAT_23ed6a4f8;
    uVar20 = 0x65;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd128,plVar3);
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x66;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd130,DAT_23ed6ccf0);
  pcVar9 = _Py_NoneStruct_exref;
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x67;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,DAT_23eedd138,_Py_NoneStruct_exref);
  lVar12 = DAT_23ed6cce8;
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x68;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  lVar4 = *(longlong *)(param_1 + 0x10);
  plVar16 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  iVar18 = *(int *)(lVar4 + 0x1410);
  *plVar16 = *plVar16 + 1;
  if (iVar18 == 0) {
    plVar17 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar16 = *(longlong **)(lVar12 + 0x20);
  }
  else {
    iVar18 = iVar18 + -1;
    *(int *)(lVar4 + 0x1410) = iVar18;
    plVar17 = *(longlong **)(lVar4 + 0x1190 + (longlong)iVar18 * 8);
    *plVar17 = 1;
  }
  lVar12 = *(longlong *)(lVar12 + 0x28);
  plVar17[2] = 0;
  plVar17[3] = 1;
  plVar17[4] = (longlong)plVar16;
  plVar17[5] = lVar12;
  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd140,plVar17);
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x69;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  lVar12 = *(longlong *)(param_1 + 0x10);
  if (*(int *)(lVar12 + 0x1188) == 0) {
    plVar16 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar18 = *(int *)(lVar12 + 0x1188) + -1;
    *(int *)(lVar12 + 0x1188) = iVar18;
    plVar16 = *(longlong **)(lVar12 + 0xf08 + (longlong)iVar18 * 8);
    *plVar16 = 1;
  }
  pcVar10 = _PyRuntime_exref;
  plVar16[2] = 0;
  plVar16[4] = 0;
  lVar12 = *(longlong *)(pcVar10 + 0x1f8);
  plVar16[3] = 0;
  lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
  lVar4 = plVar16[-1];
  puVar5 = *(undefined8 **)(lVar12 + 8);
  *puVar5 = plVar16 + -2;
  plVar16[-2] = lVar12;
  plVar16[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar12 + 8) = plVar16 + -2;
  cVar11 = FUN_23e8d9ac0(plVar1,DAT_23eedd148,plVar16);
  *plVar16 = *plVar16 + -1;
  if (*plVar16 == 0) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x6a;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd150,DAT_23ed6ccf0);
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x6b;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd158,DAT_23ed6ccf0);
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x6c;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  cVar11 = FUN_23e8d9ac0(plVar1,DAT_23eedd160,pcVar9);
  if (cVar11 == '\0') {
    plVar16 = *(longlong **)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar20 = 0x6d;
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  lVar12 = FUN_23e8dd000();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,&plStack_68,_DAT_23eedd168);
    uVar20 = 0x6e;
    plVar16 = plStack_68;
    plVar17 = plStack_58;
    uVar7 = uStack_60;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e7ff4f9;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedd170);
  if (plVar13 != (longlong *)0x0) {
    plVar14 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
    lVar12 = FUN_23e8dced0();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
      plVar16 = plStack_68;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar14 = *plVar14 + -1;
      uVar20 = 0x6e;
      plVar17 = plStack_58;
      uVar7 = uStack_60;
      plVar8 = DAT_23ed6a4f8;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
        uVar20 = 0x6e;
        plVar8 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e7ff4f9;
    }
    plVar15 = (longlong *)FUN_23e8c4790(plVar14,lVar12);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (plVar15 == (longlong *)0x0) {
      plVar16 = *(longlong **)(param_1 + 0x60);
      uVar7 = *(undefined8 *)(param_1 + 0x68);
      uVar20 = 0x6e;
      plVar17 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar13 = *plVar13 + -1;
      plVar8 = DAT_23ed6a4f8;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        uVar20 = 0x6e;
        plVar8 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e7ff4f9;
    }
    lVar12 = FUN_23e8dced0();
    if (lVar12 == 0) {
      FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
      plVar16 = plStack_68;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar15 = *plVar15 + -1;
      uVar20 = 0x6e;
      plVar17 = plStack_58;
      uVar7 = uStack_60;
      plVar8 = DAT_23ed6a4f8;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
        uVar20 = 0x6e;
        plVar8 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e7ff4f9;
    }
    *(undefined4 *)(plVar6 + 5) = 0x6e;
    lStack_70 = lVar12;
    plStack_68 = plVar15;
    plVar16 = (longlong *)FUN_23e939900(param_1,plVar13,&plStack_68,&lStack_70,_DAT_23eedd180);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if (plVar16 != (longlong *)0x0) {
      cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd188);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (cVar11 != '\0') {
        lVar12 = FUN_23e8dd000();
        if (lVar12 == 0) {
          FUN_23e915740(param_1,&plStack_68,_DAT_23eedd168);
          uVar20 = 0x6f;
          plVar16 = plStack_68;
          plVar17 = plStack_58;
          uVar7 = uStack_60;
          plVar8 = DAT_23ed6a4f8;
          goto joined_r0x00023e7ff4f9;
        }
        plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedd170);
        if (plVar13 != (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
          lVar12 = FUN_23e8dced0();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
            plVar16 = plStack_68;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              FUN_23a334bc0(plVar13);
            }
            *plVar14 = *plVar14 + -1;
            lVar12 = *plVar14;
            uVar20 = 0x6f;
            uVar19 = 0x6f;
            uVar7 = uStack_60;
            plVar17 = plStack_58;
joined_r0x00023e7ffa06:
            plVar8 = DAT_23ed6a4f8;
            if (lVar12 == 0) {
              FUN_23a334bc0(plVar14);
              plVar8 = DAT_23ed6a4f8;
              uVar20 = uVar19;
            }
            goto joined_r0x00023e7ff4f9;
          }
          plVar15 = (longlong *)FUN_23e8c4790(plVar14,lVar12);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) {
            plVar16 = *(longlong **)(param_1 + 0x60);
            uVar7 = *(undefined8 *)(param_1 + 0x68);
            uVar20 = 0x6f;
            uVar19 = 0x6f;
            plVar17 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = *plVar13 + -1;
            lVar12 = *plVar13;
joined_r0x00023e7ff998:
            plVar8 = DAT_23ed6a4f8;
            if (lVar12 == 0) {
              FUN_23a334bc0(plVar13);
              plVar8 = DAT_23ed6a4f8;
              uVar20 = uVar19;
            }
            goto joined_r0x00023e7ff4f9;
          }
          lVar12 = FUN_23e8dced0();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
            plVar16 = plStack_68;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              FUN_23a334bc0(plVar13);
            }
            *plVar15 = *plVar15 + -1;
            lVar12 = *plVar15;
            uVar20 = 0x6f;
            uVar19 = 0x6f;
            uVar7 = uStack_60;
            plVar17 = plStack_58;
joined_r0x00023e7ffa74:
            plVar8 = DAT_23ed6a4f8;
            if (lVar12 == 0) {
              FUN_23a334bc0(plVar15);
              plVar8 = DAT_23ed6a4f8;
              uVar20 = uVar19;
            }
            goto joined_r0x00023e7ff4f9;
          }
          *(undefined4 *)(plVar6 + 5) = 0x6f;
          lStack_70 = lVar12;
          plStack_68 = plVar15;
          plVar16 = (longlong *)FUN_23e939900(param_1,plVar13,&plStack_68,&lStack_70,_DAT_23eedd180)
          ;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plVar16 != (longlong *)0x0) {
            cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd190);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (cVar11 != '\0') {
              lVar12 = FUN_23e8dd000();
              if (lVar12 == 0) {
                FUN_23e915740(param_1,&plStack_68,_DAT_23eedd168);
                uVar20 = 0x70;
                plVar16 = plStack_68;
                plVar17 = plStack_58;
                uVar7 = uStack_60;
                plVar8 = DAT_23ed6a4f8;
                goto joined_r0x00023e7ff4f9;
              }
              plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eedd170);
              if (plVar13 != (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23e8d8df0(*(undefined8 *)(param_1 + 0x10),DAT_23ed6cd08);
                lVar12 = FUN_23e8dced0();
                if (lVar12 == 0) {
                  FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
                  plVar16 = plStack_68;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    FUN_23a334bc0(plVar13);
                  }
                  *plVar14 = *plVar14 + -1;
                  lVar12 = *plVar14;
                  uVar20 = 0x70;
                  uVar19 = 0x70;
                  uVar7 = uStack_60;
                  plVar17 = plStack_58;
                  goto joined_r0x00023e7ffa06;
                }
                plVar15 = (longlong *)FUN_23e8c4790(plVar14,lVar12);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (plVar15 == (longlong *)0x0) {
                  plVar16 = *(longlong **)(param_1 + 0x60);
                  uVar7 = *(undefined8 *)(param_1 + 0x68);
                  uVar20 = 0x70;
                  uVar19 = 0x70;
                  plVar17 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar13 = *plVar13 + -1;
                  lVar12 = *plVar13;
                  goto joined_r0x00023e7ff998;
                }
                lVar12 = FUN_23e8dced0();
                if (lVar12 == 0) {
                  FUN_23e915740(param_1,&plStack_68,_DAT_23eedd178);
                  plVar16 = plStack_68;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    FUN_23a334bc0(plVar13);
                  }
                  *plVar15 = *plVar15 + -1;
                  lVar12 = *plVar15;
                  uVar20 = 0x70;
                  uVar19 = 0x70;
                  uVar7 = uStack_60;
                  plVar17 = plStack_58;
                  goto joined_r0x00023e7ffa74;
                }
                *(undefined4 *)(plVar6 + 5) = 0x70;
                lStack_70 = lVar12;
                plStack_68 = plVar15;
                plVar16 = (longlong *)
                          FUN_23e939900(param_1,plVar13,&plStack_68,&lStack_70,_DAT_23eedd180);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (plVar16 != (longlong *)0x0) {
                  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd198);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  if (cVar11 != '\0') {
                    lVar12 = FUN_23e8dcd80();
                    if (lVar12 == 0) {
                      FUN_23e915740(param_1,&plStack_68,_DAT_23eedd1a0);
                      plVar16 = plStack_68;
                      plVar17 = plStack_58;
                      uVar7 = uStack_60;
                      plVar8 = DAT_23ed6a4f8;
                      uVar20 = 0x71;
                    }
                    else {
                      *(undefined4 *)(plVar6 + 5) = 0x71;
                      plVar16 = (longlong *)FUN_23e91bfe0(param_1,lVar12);
                      if (plVar16 != (longlong *)0x0) {
                        cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1a8,plVar16);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        if (cVar11 != '\0') {
                          cVar11 = FUN_23e8d9ac0(plVar1,DAT_23eedd1b0,pcVar9);
                          if (cVar11 == '\0') {
                            plVar16 = *(longlong **)(param_1 + 0x60);
                            plVar17 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar7 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = DAT_23ed6a4f8;
                            uVar20 = 0x72;
                          }
                          else {
                            plVar16 = (longlong *)FUN_23e8d6ad0(param_1);
                            cVar11 = FUN_23e8d9ac0(plVar1,DAT_23eedd1b8,plVar16);
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              FUN_23a334bc0(plVar16);
                            }
                            if (cVar11 == '\0') {
                              plVar16 = *(longlong **)(param_1 + 0x60);
                              plVar17 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uVar7 = *(undefined8 *)(param_1 + 0x68);
                              plVar8 = DAT_23ed6a4f8;
                              uVar20 = 0x73;
                            }
                            else {
                              cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1c0,DAT_23ed6ccf0);
                              if (cVar11 == '\0') {
                                plVar16 = *(longlong **)(param_1 + 0x60);
                                plVar17 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar7 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = DAT_23ed6a4f8;
                                uVar20 = 0x74;
                              }
                              else {
                                cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1c8);
                                if (cVar11 == '\0') {
                                  plVar16 = *(longlong **)(param_1 + 0x60);
                                  plVar17 = *(longlong **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar7 = *(undefined8 *)(param_1 + 0x68);
                                  plVar8 = DAT_23ed6a4f8;
                                  uVar20 = 0x75;
                                }
                                else {
                                  cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1d0,DAT_23ed6ccf0);
                                  if (cVar11 == '\0') {
                                    plVar16 = *(longlong **)(param_1 + 0x60);
                                    plVar17 = *(longlong **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar7 = *(undefined8 *)(param_1 + 0x68);
                                    plVar8 = DAT_23ed6a4f8;
                                    uVar20 = 0x76;
                                  }
                                  else {
                                    cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1d8,DAT_23ed6ccf0);
                                    if (cVar11 == '\0') {
                                      plVar16 = *(longlong **)(param_1 + 0x60);
                                      plVar17 = *(longlong **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar7 = *(undefined8 *)(param_1 + 0x68);
                                      plVar8 = DAT_23ed6a4f8;
                                      uVar20 = 0x77;
                                    }
                                    else {
                                      cVar11 = FUN_23e8d9ac0(plVar1,_DAT_23eedd1e0,DAT_23ed6cd08);
                                      if (cVar11 != '\0') {
                                        FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                        *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
                                        *plVar1 = *plVar1 + -1;
                                        if (*plVar1 == 0) {
                                          FUN_23a334bc0(plVar1);
                                        }
                                        *plVar2 = *plVar2 + -1;
                                        if (*plVar2 == 0) {
                                          FUN_23a334bc0(plVar2);
                                        }
                                        *plVar3 = *plVar3 + -1;
                                        if (*plVar3 != 0) {
                                          return pcVar9;
                                        }
                                        FUN_23a334bc0(plVar3);
                                        return pcVar9;
                                      }
                                      plVar16 = *(longlong **)(param_1 + 0x60);
                                      plVar17 = *(longlong **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      uVar7 = *(undefined8 *)(param_1 + 0x68);
                                      plVar8 = DAT_23ed6a4f8;
                                      uVar20 = 0x78;
                                    }
                                  }
                                }
                              }
                            }
                          }
                          goto joined_r0x00023e7ff4f9;
                        }
                      }
                      plVar16 = *(longlong **)(param_1 + 0x60);
                      plVar17 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar7 = *(undefined8 *)(param_1 + 0x68);
                      plVar8 = DAT_23ed6a4f8;
                      uVar20 = 0x71;
                    }
                    goto joined_r0x00023e7ff4f9;
                  }
                }
              }
              plVar16 = *(longlong **)(param_1 + 0x60);
              plVar17 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar7 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = DAT_23ed6a4f8;
              uVar20 = 0x70;
              goto joined_r0x00023e7ff4f9;
            }
          }
        }
        plVar16 = *(longlong **)(param_1 + 0x60);
        uVar20 = 0x6f;
        plVar17 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = DAT_23ed6a4f8;
        goto joined_r0x00023e7ff4f9;
      }
    }
  }
  plVar16 = *(longlong **)(param_1 + 0x60);
  uVar20 = 0x6e;
  plVar17 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar7 = *(undefined8 *)(param_1 + 0x68);
  plVar8 = DAT_23ed6a4f8;
joined_r0x00023e7ff4f9:
  DAT_23ed6a4f8 = plVar8;
  if (plVar17 == (longlong *)0x0) {
    if (plVar8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar8;
      *plVar8 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar8;
    }
    pcVar9 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar12 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar20;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar4 = plVar13[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar13 + -2;
    plVar13[-2] = lVar12;
    plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar17;
    if ((longlong *)plVar17[3] != plVar6) {
      if (plVar8 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar8;
        *plVar8 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar8;
      }
      pcVar9 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      lVar12 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar20;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar4 = plVar13[-1];
      puVar5 = *(undefined8 **)(lVar12 + 8);
      *puVar5 = plVar13 + -2;
      plVar13[-2] = lVar12;
      plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
      lVar4 = *plVar17;
      *(longlong **)(lVar12 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar17;
      if (lVar4 == 0) {
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5e2be,plVar1,plVar2,plVar3);
  if (_DAT_23eede940 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eede940 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar12 + 0x28);
  plVar17 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plVar16,uVar7,plVar13);
  return (code *)0x0;
}
